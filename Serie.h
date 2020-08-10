#pragma once

class Serie 
{

	public:
		Serie();
		Serie( int, string);

		void setId( int id ) { this -> id = id; };
		void setNombre( string nombre ) { this -> nombre = nombre; };

		int getId() { return id; };
		string getNombre() { return nombre; };
		void mostrar();  // PS: endl al final de cout 

	private:
		int id;
		string nombre;

};

Serie::Serie()
{
	id     = 0;
	nombre = "Nombre Serie N/A";

}

Serie::Serie( int id, string nombre)
{
	this -> id = id;
	this -> nombre = nombre;
}

void Serie::mostrar()
{
	cout << "Serie:      " << nombre << endl;
}