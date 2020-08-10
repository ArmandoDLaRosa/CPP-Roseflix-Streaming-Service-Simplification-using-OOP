#pragma once

class Video 
{

	public:
		Video();
		Video(int, int, int, string, string );

		void setId( int id ) { this -> id = id; };
	 	void setDuracion( int duracion ) { this -> duracion = duracion; };
		void setCalificacion( int calificacion ) { this -> calificacion = calificacion; };
		void setNombre( string nombre ) { this -> nombre = nombre; };
		void setGenero( string genero ) { this -> genero = genero; };

		int getId() { return id; };
		int getDuracion() { return duracion; };
		int getCalificacion() { return calificacion; };
		string getNombre() { return nombre; };
		string getGenero() { return genero; };

		virtual  void mostrar() = 0;

	protected:

		int id, duracion, calificacion;
		string  nombre, genero;

};

Video::Video()
{

	id = 0;
	duracion = 0;
	calificacion = 1;
	nombre = "N/A";
	genero = "Unknown";

}

Video::Video(int id, int duracion, int calificacion, string nombre, string genero )
{
    this -> id = id;
	this -> duracion = duracion;
	this -> calificacion = calificacion;
	this -> nombre = nombre;
	this -> genero = genero;
}