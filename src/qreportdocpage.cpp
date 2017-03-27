/***************************************************************************
 *   Copyright (C) 2010 by Hamed Masafi   *
 *   Hamed.Masafi@gmAIL.COM   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "qreportdocpage.h"

LEAF_BEGIN_NAMESPACE

LReportPage::LReportPage(QGraphicsItem *parent): LReportWidgetBase(parent)
{
    this->setZValue(0);
    this->setIsMovable(false);

    setWidgetType(Page);
    _gridType = NoGrid;

    // setAcceptedMouseButtons( Qt::RightButton );
}


LReportPage::~LReportPage()
{}


void LReportPage::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QPen penPage(Qt::black, 0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QBrush brushPage(Qt::white);
    painter->setBrush(brushPage);
    painter->setPen(penPage);

    QRectF rc = this->rect();

    // draw page frame
    painter->fillRect(rc, Qt::white);
    painter->drawRect(rc);

    // set margins
    rc.setTopLeft(QPoint(_marginLeft, _marginTop));
    rc.setWidth(rc.width() - _marginRight);
    rc.setHeight(rc.height() - _marginBottom);

    if (_gridType == DotGrid)
        for (int i = rc.left(); i <= rc.right(); i = i + _gridSize)
            for (int j = rc.top(); j <= rc.bottom(); j = j + _gridSize)
                painter->drawPoint(i, j);


    if (_gridType == LinesGrid) {
        painter->setPen(QPen(Qt::lightGray));
        for (int i = rc.left(); i <= rc.right(); i = i + _gridSize)
            painter->drawLine(i, rc.top(), i, rc.bottom());
        for (int j = rc.top(); j <= rc.bottom(); j = j + _gridSize)
            painter->drawLine(rc.left(), j, rc.right(), j);
    }//if

    // draw inside margins
    painter->setBrush(Qt::NoBrush);
    painter->setPen(QPen(QColor(180, 190, 220)));
    painter->drawRect(rc);

}

QRect LReportPage::documentArea() const
{
    return QRect(_marginLeft,
                 _marginTop,
                 this->rect().width() - _marginLeft - _marginRight,
                 this->rect().height() - _marginTop - _marginBottom);
}


void LReportPage::setGridSize(qreal gridSize)
{
    _gridSize = gridSize;

    this->update(this->boundingRect());
}

void LReportPage::setMargins(qreal left, qreal top, qreal right, qreal bottom)
{
    _marginTop = top;
    _marginLeft = left;
    _marginRight = right;
    _marginBottom = bottom;

    this->update(this->boundingRect());
}


void LReportPage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
    emit selectedChanged();
}

LEAF_END_NAMESPACE
