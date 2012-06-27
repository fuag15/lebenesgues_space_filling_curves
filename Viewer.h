#ifndef __Viewer_h__
#define __Viewer_h__

#include <QGLWidget>

class Viewer : public QGLWidget
{
    Q_OBJECT

  public:
    Viewer();
    
  public slots:
    void setRec(int newRec);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

  protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void step(int currentR, int numR, float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float offset);
    
    // initial variables corners of bux, offset and num recusion
    float axx;
    float ayx;
    float bxx;
    float byx;
    float cxx;
    float cyx;
    float dxx;
    float dyx;
    float offsetx;
    int numR;
};

#endif