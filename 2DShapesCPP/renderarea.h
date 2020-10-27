#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {
        Astroid,
        Cycloid,
        HuygensCycloid,
        HypoCycloid
    };

    void setBackgroundColor(QColor color) {mBackgroundColor = color;} //setter
    QColor backgroundColor() const {return mBackgroundColor;} //getter

    void setShapeColor(QColor color) {mShapeColor = color;}
    QColor shapeColor() const {return mShapeColor;}

    void setShape(ShapeType shape){mShape = shape; on_shape_changed();} //setter
    ShapeType shape() const{return mShape;} //getter

    void setScale(float scale) {mScale = scale; repaint();} //setter
    float scale() const {return mScale;} //getter

    void setInterval(float interval) {mIntervalLength = interval; repaint();} //setter
    float interval() const {return mIntervalLength;}//getter

    void setStepCount(int count) {mStepCount = count; repaint();}//setter
    int stepCount() const {return mStepCount;} //getter
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE; //overwrites and allows us to create our own paint



signals:

private:
    void on_shape_changed();
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute(float t); //dispatcher function based off shape
private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;

};

#endif // RENDERAREA_H
