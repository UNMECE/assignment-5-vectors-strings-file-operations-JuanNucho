
#ifndef PIXEL_H
#define PIXEL_H

struct _pixel
{
    float r;  // Red component (0.0 to 1.0)
    float g;  // Green component (0.0 to 1.0)
    float b;  // Blue component (0.0 to 1.0)
    int x;    // x-coordinate (location on screen)
    int y;    // y-coordinate (location on screen)
};

typedef struct _pixel Pixel; // Typedef to use 'Pixel' as a shorthand

#endif