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

#ifndef RWIDGETRESIZER_H
#define RWIDGETRESIZER_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QList>
#include <QHash>
#include <qtreportglobal.h>

class QPoinF;

LEAF_BEGIN_NAMESPACE

class QReportWidgetBase;
class QReportMoveEvent;
class QReportResizeEvent;
class QReportResizeHandle :  public QObject, public QGraphicsEllipseItem
{
      Q_OBJECT

   public:
      QReportResizeHandle ( qreal x, qreal y, qreal radius, QGraphicsItem  *parent = 0 );

      void mouseMoveEvent ( QGraphicsSceneMouseEvent  *event );
      void mousePressEvent ( QGraphicsSceneMouseEvent  *event );
      void mouseReleaseEvent ( QGraphicsSceneMouseEvent  *event );

      QPointF centerPoint() const;
      QPointF lastPoint() const;

      ResizeDirection resizeDirection() const;
      void setResizeDirection ( ResizeDirection value );

      void setScale ( qreal scale );

   private:
      qreal _radius;
      bool mousePressed;
      QPointF _lastPoint;
      ResizeDirection m_resizeDirection;

   signals:
      void moving ( QPointF point );
      void moved();
};

class QReportWidgetResizer : public QObject
{
      Q_OBJECT

   public:
      QReportWidgetResizer ( QGraphicsScene *parent );
      ~QReportWidgetResizer();

      void setVisible ();
      void setVisible ( bool visible );
      void setActiveItem ( QReportWidgetBase *item );
      void setHandlesOnItem ( QRectF rc );
      qreal scale();
      void setScale ( qreal scale );
      void refreshHandles();
      void refresh();

      QList<QReportWidgetBase*> selectedWidgets();
      void clear();
      void clear(bool unselectWidgets);
      void addWidget( QReportWidgetBase *Widget );

      void refreshWidgets();

      bool isWidgetSelected(QReportWidgetBase *Widget);

      QList<QReportWidgetBase *> selectedWidgets() const;
   private:
      QGraphicsScene parent;

      QReportResizeHandle  *resizerTL,   *resizerT,   *resizerTR;
      QReportResizeHandle  *resizerL ,                *resizerR ;
      QReportResizeHandle  *resizerBL,   *resizerB,   *resizerBR;
      QList<QReportResizeHandle*> handles;

      QGraphicsScene *parentScene;


      qreal m_scale;
      qreal _marginTop;
      qreal _marginLeft;
      qreal _gridSize;

      QRectF selectionRect;
      QRectF resizeRect;
      QHash<QReportWidgetBase*, QRectF>  _widgetRects;

      QList<QReportWidgetBase *> _selectedWidgets;

      void setResezeHandlePos ( QGraphicsEllipseItem *handle, QPointF pos );
      void setResezeHandlePos ( QGraphicsEllipseItem *handle, QPointF pos1, QPointF pos2 );

      void proccessNewRect( QRectF rc );

   signals:
      void pointGridNeeded( QReportMoveEvent* );
      void sizeGridNeeded( QReportResizeEvent* );
      void resized();

   public slots:
      void handleMoving ( QPointF point );
      void widgetMoving ( QReportMoveEvent *event );
};

LEAF_END_NAMESPACE

#endif
