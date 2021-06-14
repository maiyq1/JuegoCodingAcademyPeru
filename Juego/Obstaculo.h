#pragma once
#include "Entidad.h"

class Obstaculo : public Entidad
{
public:
	Obstaculo(Bitmap^ img)
	{
		x = rand() % 200;
		y = rand() % 200;

		ancho = img->Width;
		alto = img->Height;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->DrawImage(img, Area());
		g->DrawRectangle(Pens::Black, Area());
	}
};

class Obstaculos
{
private:
	vector<Obstaculo*> obstaculos;

public:
	Obstaculos(int n, Rectangle obj, Bitmap^ img)
	{
		for (int i = 0; i < n; i++)
		{
			Obstaculo* obs = new Obstaculo(img);
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				obstaculos.push_back(obs);
			else
			{
				delete obs;
				i--;
			}
		}
	}
	~Obstaculos()
	{
		for (int i = 0; i < obstaculos.size(); i++)
			delete obstaculos.at(i);
	}

	bool Colision(Rectangle obj)
	{
		for each (Obstaculo * obs in obstaculos)
		{
			if (obs->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mover(Graphics^ g)
	{
		for each (Obstaculo* obs in obstaculos)
		{
			obs->Mover(g);
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for (Obstaculo * obs : obstaculos)
		{
			obs->Mostrar(g, img);
		}
	}
};