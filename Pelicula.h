#pragma once

#include "Video.h"

class Pelicula : public Video 
{

	public:
		Pelicula();
		Pelicula( int, int, int, string, string );

		void mostrar();
		
};

Pelicula::Pelicula() : Video()
{

}

Pelicula::Pelicula( int id, int duracion, int calificacion, string nombre, string genero ) :
Video( id , duracion, calificacion, nombre, genero )
{

}

void Pelicula::mostrar()
{
	cout << "Película:     " << nombre << endl;
}