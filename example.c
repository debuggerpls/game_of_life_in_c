/*
 *	Projekt: Beispiel fuer die Verwendung von SimpleDraw
 *	Datei:   example.c
 *	Autor:   Martin Graefe, martin.e.graefe@iem.thm.de
 */

#include "simple_draw.h"

int main(int argc, char *argv[])
{
  int x, y, r, r2, x0, y0;

  /* Grafik loeschen */
  ClearGraphic();

  /* Grafik-Cursor positionieren */
  MoveTo(100, 50);

  /* Linie vom Grafik-Cursor aus zeichnen */
  DrawTo(600, 50);
  DrawTo(600, 100);
  DrawTo(100, 100);
  DrawTo(100, 50);

  /* Text ausgeben */
  PlaceText(280, 69, "Beispiel für SimpleDraw");

  /* Linienfarbe und -dicke einstellen */
  SetPen(0, 80, 200, 3);

  /* Linie mit Anfangs- und Endpunkt zeichnen */
  DrawLine(300, 300, 400, 300);
  DrawLine(400, 300, 350, 200);
  DrawLine(350, 200, 300, 300);

  /* einzelne farbige Pixel setzen */
  x0 = 350;  // Kreis aus Pixeln zeichnen
  y0 = 260;
  r = 80;
  r2 = (r+1)*r;  // (r+0.5)^2 --> Radius-Quadrat mit Rundung
  x = 0;
  y = r;
  while (y >= 0)
  {
    DrawPixel(x0+x, y0-y, x*3, 50, y*3);
    DrawPixel(x0-x, y0-y, x*3, 50, y*3);
    DrawPixel(x0+x, y0+y, x*3, 50, y*3);
    DrawPixel(x0-x, y0+y, x*3, 50, y*3);
    if (y > x)
    {
      x++;
      if (x*x + y*y >= r2)
        y--;
    }
    else
    {
      y--;
      if (x*x + y*y < r2)
        x++;
    }
  }

  if ((argc == 2) && (argv[1][0] == 'b'))
  {
    ResizeGraphic(50, 20, 760, 540);
    for (y=350; y<500; y++)
      for (x=0; x<700; x++)
        DrawPixel(x+30, y+20, 250-y, 0, x/3);
  }

  return 0;
}
