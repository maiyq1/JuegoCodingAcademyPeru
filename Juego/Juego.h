#pragma once
#include "Jugador.h"
#include "Obstaculo.h"

ref class ControladorJuego
{
private:
	Jugador* jugador;
	Obstaculos* obstaculos;

	Bitmap^ imgTrol;
	Bitmap^ imgJugador;
public:
	ControladorJuego()
	{
		imgTrol = gcnew Bitmap("img/trol.png");
		imgJugador = gcnew Bitmap("img/jugador.png");

		jugador = new Jugador(imgJugador);
		obstaculos = new Obstaculos(5, jugador->Area(), imgTrol);
	}
	~ControladorJuego()
	{
		delete jugador, obstaculos;
		delete imgTrol;
	}

	void MovimientoJugador(bool accion, Keys tecla)
	{
		int v = 3;

		if (accion == true)
		{
			if (tecla == Keys::Up)
			{
				jugador->SetDY(-v);
				jugador->SetAccion(CaminarArriba);
			}
			else if (tecla == Keys::Down)
			{
				jugador->SetDY(v);
				jugador->SetAccion(CaminarAbajo);
			}
			else if (tecla == Keys::Left)
			{
				jugador->SetDX(-v);
				jugador->SetAccion(CaminarIzquierda);
			}
			else if (tecla == Keys::Right)
			{
				jugador->SetDX(v);
				jugador->SetAccion(CaminarDerecha);
			}
		}
		else
		{
			if (tecla == Keys::Up)
				jugador->SetDY(0);
			else if (tecla == Keys::Down)
				jugador->SetDY(0);
			else if (tecla == Keys::Left)
				jugador->SetDX(0);
			else if (tecla == Keys::Right)
				jugador->SetDX(0);
		}
	}

	void Mover(Graphics^ g)
	{
		if (obstaculos->Colision(jugador->NextArea()) == false)
			jugador->Mover(g);

		obstaculos->Mover(g);
	}
	void Mostrar(Graphics^ g)
	{
		jugador->Mostrar(g, imgJugador);
		obstaculos->Mostrar(g, imgTrol);
	}
};