#ifndef VGEGROUP_H
#define VGEGROUP_H

#include "vgeshape.h"

class VGEGroup;


class VGEGroup : public VGEShape {
    Q_OBJECT

public:
    explicit VGEGroup(QObject *parent = nullptr, QColor color = vge::SHAPE_DEFAULT_COLOR)
        : VGEShape(parent, std::move(color))
    {}

    explicit VGEGroup(QObject *parent, QColor color, QList<VGEShape *> shList);

    void clip(const QPointF &fp, const QPointF &lp) override;
    void move(const QPointF &displacement) override;
    void scale(qreal coefficeint) override;
    void handleMousePressEvent(QMouseEvent *event) override;
    void handleMouseMoveEvent(QMouseEvent *event) override;
    void handleMouseReleaseEvent(QMouseEvent *event) override;
    VGERShape& getRaster() override;

    QList<VGEShape *> getList()
    { return _shList; }

    VGEShape * get(size_t index);
    void add(VGEShape * shape);
    void del(const QString &name);

    void draw() override;


private:
    QList<VGEShape *> _shList;

};

#endif // VGEGROUP_H
