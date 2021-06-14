#pragma once
#include "Dependencias.h"

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx;
public:
	Entidad()
	{
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	}

	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}

	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Black, Area());
	}
};