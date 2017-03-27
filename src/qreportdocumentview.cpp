/***************************************************************************
 *   QtReport                                                              *
 *   Qt Report Builder Soultion                                            *
 *                                                                         *
 *   Copyright (C) 2010 by Hamed Masafi                                    *
 *   Hamed.Masafi@GMail.COM                                                *
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

#include <QGraphicsSceneMouseEvent>
#include <QScrollBar>

#include "qreportdocumentview.h"

LEAF_BEGIN_NAMESPACE

LReportDocumentView::LReportDocumentView ( QWidget *parent ) : QGraphicsView ( parent )
{
   connect ( horizontalScrollBar(), SIGNAL ( valueChanged ( int ) ),
             this,                  SIGNAL ( horizontalValueChanged ( int ) ) ) ;

   connect ( verticalScrollBar(), SIGNAL ( valueChanged ( int ) ),
             this,                SIGNAL ( verticalValueChanged ( int ) ) ) ;

}


LReportDocumentView::LReportDocumentView ( QGraphicsScene *scene, QWidget *parent ) : QGraphicsView ( scene, parent )
{
}


LReportDocumentView::~LReportDocumentView()
{
}

void LReportDocumentView::setPageSize ( int , int  )
{
}

void LReportDocumentView::mouseMoveEvent ( QGraphicsSceneMouseEvent  *mouseEvent )
{
   emit mouseMove ( mouseEvent );
}

void LReportDocumentView::mousePressEvent ( QGraphicsSceneMouseEvent  *mouseEvent )
{
   emit mousePress ( mouseEvent );
}
/*
void LReportDocumentView::mouseReleaseEvent ( QGraphicsSceneMouseEvent  *mouseEvent )
{
   emit mouseRelease ( mouseEvent );
}*/


void LReportDocumentView::scrollContentsBy ( int dx, int dy )
{
   emit scroll( dx, dy );
   QGraphicsView::scrollContentsBy(dx, dy);
   //update();
   viewport()->repaint();
}

LEAF_END_NAMESPACE
