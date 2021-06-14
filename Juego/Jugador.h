#pragma once
#include "Entidad.h"

enum SpriteJugador
{
	DispararArriba,
	DispararIzquierda,
	DispararAbajo,
	DispararDerecha,

	AtacarArriba,
	AtacarIzquierda,
	AtacarAbajo,
	AtacarDerecha,
	
	CaminarArriba,
	CaminarIzquierda,
	CaminarAbajo,
	CaminarDerecha,

	Morir
};

class Jugador : public Entidad
{
private:
	SpriteJugador accion;
public:
	Jugador(Bitmap ^img)
	{
		x = 60; y = 60;
		dx = dy = 0;

		ancho = img->Width / 13;
		alto = img->Height / 13;

		accion = CaminarArriba;
	}

	void SetAccion(SpriteJugador value)
	{
		accion = value;
	}

	void Mover(Graphics^ g)
	{
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
			y += dy;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		g->DrawRectangle(Pens::Black, Area());

		if (dx != 0 || dy != 0)
		{
			if (accion >= DispararArriba && accion <= DispararDerecha)
				IDx = (IDx + 1) % 13;
			else if (accion >= AtacarArriba && accion <= AtacarDerecha)
				IDx = (IDx + 1) % 8;
			else if (accion >= CaminarArriba && accion <= CaminarDerecha)
				IDx = (IDx + 1) % 9;
			else if (accion == Morir)
				IDx = (IDx + 1) % 6;
		}
	}
};