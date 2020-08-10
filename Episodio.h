#pragma once

#include "Video.h"


class Episodio : public Video 
{

	public:
		Episodio();
		Episodio( int, int, int, string, string, string, string, string);
		
		void setSerie( string serie ) { this -> serie = serie; };
		void setNumEpisodio( string numEpisodio ) { this -> numEpisodio = numEpisodio; };
		void setNumTemporada( string numTemporada ) { this -> numTemporada = numTemporada; };

		string getSerie() { return serie; };
		string getNumEpisodio() { return numEpisodio; };
		string getNumTemporada() { return numTemporada; };

		void mostrar();

	private:
		string serie, numEpisodio, numTemporada;

};

Episodio::Episodio() : Video()
{
	serie        = "Nombre Serie N/A";
	numEpisodio  = "Numero episodio N/A";
	numTemporada = "Numero episodio N/A";
}

Episodio::Episodio( int id, int duracion, int calificacion, string nombre, string genero, string serie, string numEpisodio, string numTemporada ) : Video( id ,  duracion,  calificacion, nombre, genero )

{
	this -> serie = serie;
    this -> numEpisodio = numEpisodio;
	this -> numTemporada = numTemporada;
}

void Episodio::mostrar()
{
	cout << "Episodio:     " << nombre << endl;
}