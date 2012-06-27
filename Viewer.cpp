#include "Viewer.h"

Viewer::Viewer():QGLWidget() // sets default values
{
    axx = 0.0;
    ayx = 0.0;
    bxx = 0.0;
    byx = 1.0;
    cxx = 1.0;
    cyx = 1.0;
    dxx = 1.0;
    dyx = 0.0;
    offsetx = 0.1;
    numR = 5;
    resize(400, 400);
}

void Viewer::setRec(int newRec) // recieve a signal from slider and rec
{
    numR = newRec;
    updateGL();
}

void Viewer::initializeGL()
{
}

void Viewer::resizeGL(int w, int h) // sets grid
{
    glLoadIdentity();
    glViewport(0, 0, w, h);
    glOrtho(0, 1, 0, 1, 0, 1);
}

void Viewer::paintGL() // paints the box
{

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    step(1, numR, axx, ayx, bxx, byx, cxx, cyx, dxx, dyx, offsetx);
    glEnd();

}

QSize Viewer::minimumSizeHint() const
{
     return QSize(50, 50);
}

QSize Viewer::sizeHint() const
{
     return QSize(400, 400);
}

void Viewer::step(int currentR, int numR, float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float offset) // recursively handle everything
{
    float cenx, ceny, cenoff;
    if(numR == 0) // if zero recursions do nothing
    {
	return;
    }
    else if(currentR >= numR) //number of recursions is met plot graph
    {
	glVertex2f((cx - offset), (cy - offset));
	glVertex2f((dx - offset), (dy + offset));
	glVertex2f((bx + offset), (by - offset));
	glVertex2f((ax + offset), (ay + offset));
    }
    else //RECURSE IN THE CORRECT ORDER CDBA
    {
	cenx = ax + ((dx - ax)/2.0);
	ceny = ay + ((by - ay)/2.0);
	cenoff = offset/2.0;
	step(currentR + 1, numR, cenx, ceny, cenx, by, cx, cy, dx, ceny, cenoff); // do upper right;
	step(currentR + 1, numR, cenx, ay, cenx, ceny, cx, ceny, dx, dy, cenoff); // do lower right
	step(currentR + 1, numR, ax, ceny, bx, by, cenx, cy, cenx, ceny, cenoff); // do upper left
	step(currentR + 1, numR, ax, ay, ax, ceny, cenx, ceny, cenx, ay, cenoff); // do lower left
    }
    return;
}


