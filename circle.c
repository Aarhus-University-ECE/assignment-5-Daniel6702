#include <malloc.h>
#include "circle.h"

void fiveCircles(circle c[]) {
	for (int i = 0; i < 5; i++) {
		c[i].r = i;
		c[i].p.x = i;
        c[i].p.y = i;
	}
}

int circleIsValid(const circle * c) {
	if ( (*c).r > 0 ) { //get value (circle struct) at pointer, if radius of circle > 0
        return 1; //return true (1) if circle is valid
    } else {
        return 0;
    }
}

void translate(circle* c, const point* p) {
	(*c).p.x += (*p).x; //adds coords of the two points
    (*c).p.y += (*p).y;
}
