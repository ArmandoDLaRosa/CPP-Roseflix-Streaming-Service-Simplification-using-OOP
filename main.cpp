// Armando De La Rosa  (04/06/2020) ROSEFLIX 
// - Versión muy simplificad de un servicio de streaming -

#include <iostream>
#include <fstream>

using namespace std;

#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"

// Esta función abre un archivo de texto y crea un array de objectos Vídeos (episodios y películas) y su contador.
void carga_Datos_Videos( Video *listaVideos[], int &numObjetoV)
{
	char tipoVideo;
	int  id, duracion, calificacion;
	string nombre, genero, serie, numEpisodio, numTemporada;

	ifstream archivoVideo;
	archivoVideo.open("Files/datosVideos.txt");

	while ( archivoVideo >> tipoVideo ) 
	{
		if( tipoVideo == 'p' )
		{
			archivoVideo >> id >> nombre >> genero >> duracion >> calificacion;
			listaVideos[numObjetoV++] = new Pelicula(id, duracion,  calificacion,  nombre, genero);
    	}
		
		else
		{
    		archivoVideo >> id >> nombre >> genero >> duracion >> calificacion >> serie >> numEpisodio >> numTemporada;

			listaVideos[numObjetoV++] = new Episodio(id,  duracion,  calificacion,  nombre,  genero,serie,  numEpisodio,  numTemporada );
    	}
	}
	archivoVideo.close();
}

// Esta función abre un archivo de texto y crea un array de objectos Series y su contador.
void carga_Datos_Series( Serie *listaSeries[], int &numObjetoS)
{
	int id; 
	string nombre;

	ifstream archivoSerie;
	archivoSerie.open("Files/datosSeries.txt");

	while (archivoSerie >> id)
	{
					
			archivoSerie >> nombre;
			listaSeries[numObjetoS++] = new Serie(id, nombre);

	}
	archivoSerie.close();
}

// Esta función muestra una lista de Películas, usando los objetos del array de objetos de Vídeo. 
void muestra_Lista_Peliculas(Video *listaVideos[], int numObjetoV)
{
	cout << "LISTA DE PELÍCULAS EN ROSEFLIX" << endl << endl;

	for ( int c = 0; c < numObjetoV; c++ )
	{
		if (typeid(*listaVideos[c]) == typeid(Pelicula))
			listaVideos[c]->mostrar();
	}
}


// Esta función muestra una lista de Series, usando los objetos del array de objetos de Serie.
void muestra_Lista_Series(Serie *listaSeries[], int numObjetoS)
{

	cout << "LISTA DE SERIES EN ROSEFLIX" << endl << endl;

	for ( int c = 0; c < numObjetoS; c++ )
	{
		listaSeries[c] -> mostrar();
	}
}

// Este menú se usa en dos funciones muestra_Filtro_Rating_Videos(...) y muestra_Filtro_Rating_Pelicula(...)
// Las condiciones de uso para recibir datos se especifican en las funciones donde se usa.
int menuRatings()
{
	int opcionMenu;

	cout << "Escoge la calificacion a filtrar: " << endl << endl;

	cout << "0  --Para salir al menú principal--" << endl;
	cout << "1    No recomandable!" << endl;
	cout << "2    Meh!" << endl;
	cout << "3    Palomera!" << endl;
	cout << "4    Divertida!" << endl;
	cout << "5    Debes Verla!"<< endl;
	
	cout << "     Teclea el número: " ;
	cin  >> opcionMenu;
	cout << endl;

	return opcionMenu;
}

// Esta funcion muestra un menú de calificaciones y filtra el array de vídeos con base a una calificación
// en número (dígito 1 al 5) proporcionada por el usuario al teclar y hacer enter.
void muestra_Filtro_Rating_Videos(Video *listaVideos[], int numObjetoV)
{
	int calificacion, calificacionTmp;
	bool present;

	cout << "FILTRA PARA VER SOLO LOS MEJORES VÍDEOS" << endl << endl;
	
	do
	{	
		present =  false;
		calificacion = menuRatings();
		cout << endl;
		for ( int c = 0; c < numObjetoV; c++ )
		{
			calificacionTmp  = listaVideos[c]->getCalificacion();

			if (calificacionTmp == calificacion )
			{
				listaVideos[c]->mostrar();
				cout << "Calificación: " << listaVideos[c]->getCalificacion() << endl << endl;
				present = true;
			}
		}
		// Si la función no encuentra un vídeo con una calificación de los dígitos (1-5),
		// arroja el siguiente mensaje al usuario.
		if ( calificacion !=0 && calificacion <5 && calificacion >= 1 && present != true)
		{
			cout << "No se ha encontrado un vídeo de calificacion: " << endl << calificacion << endl << endl;
		}
		// Si la función recibe un número fuera de los dígitos (1-5) manda el siguiente mensaje.
		if ( calificacion >5 || calificacion <0)
		{ 
			cout << "No existe esa calificación, prueba otra vez" << endl << endl;
		}

	} while( calificacion != 0); 
}

// Este menú se usa en la función muestra_Filtro_Genre_Videos(...), al igual que menuRatings(),
// las condiciones de los datos se revisan en la función en que se usa.
int menuGenre()
{
	int opcionMenu;

	cout << "Escoge el género a filtrar: " << endl << endl;

	cout << "0  --Para salir al menú principal--" << endl;
	cout << "1    Ciencia ficcion" << endl;
	cout << "2    Accion" << endl;
	cout << "3    Drama" << endl;
	cout << "4    Musical" << endl;
	cout << "5    Animacion"<< endl;
	cout << "6    Comedia" << endl;
	
	cout << "     Teclea el número: " ;
	cin  >> opcionMenu;
	cout << endl;

	return opcionMenu;
}

// Esta función muestra un menú de género, precargado con géneros default. Para que el usuario
// Filtre el array de vídeos con base al género de su preferencia. El usuario registra un
// número (Dígito 1-6) para seleccionar el género. El dígito 0 lo regresa al menú principal.
void muestra_Filtro_Genre_Videos(Video *listaVideos[], int numObjetoV)
{
	bool present;
	int opcionMenu;
	string genero, generoTmp;
	
	string genre[6]= {"Ciencia_ficcion","Accion","Drama", "Musical","Animacion","Comedia"};

	cout << "FILTRA PARA ENCONTRAR VÍDEOS DE TU GÉNERO FAVORITO" << endl << endl;

	do
	{	
		present =  false;
		opcionMenu = menuGenre();

		if (opcionMenu>=1 && opcionMenu <=6)
		{
			opcionMenu--;
			genero = genre[opcionMenu];
			cout << endl;

			for ( int c = 0; c < numObjetoV; c++ )
			{
				generoTmp  = listaVideos[c]->getGenero();

				if (generoTmp == genero )
				{
					listaVideos[c]->mostrar();
					cout << "Genero:       " << listaVideos[c]->getGenero() << endl << endl;
					present = true;
				}
			}
			if (opcionMenu==0)
				opcionMenu++;
		}
		// Si la función no encuentra un vídeo del genero (dígitos 1-6),
		// arroja el siguiente mensaje
		if ( opcionMenu !=0 && opcionMenu <6 && opcionMenu >= 1 && present != true)
		{
			cout << "No se ha encontrado un vídeo de género: " << endl << genero << endl << endl;
		}
		// Si el usuario escribe un número negativo o simplemente un número fuera
		// del rango 1-6, incluido 1 y el 6, arroja el siguiente mensaje.
		if ( opcionMenu >6 || opcionMenu <0)
		{ 
			cout << "No existe el género, prueba otra vez" << endl << endl;
		}
	} while(opcionMenu != 0);
}

//  Este menu se usa en la función muestra_Filtro_Serie_Videos(...) para proporcionar con base
//  a las series presentes en el servicio de streaming, sugerencias a elegir.
string menuSerie(Serie *listaSeries[], int numObjetoS)
{
	string serie;
	muestra_Lista_Series(listaSeries, numObjetoS);
	cout << endl << "   OPCIONES      ESCRIBE";
	cout << endl << "   ________      ________";
	cout << endl << "   Ir menú          0" << endl;
	cout << "   Ver Serie    Su título" << endl;
	cout << "   Búsqueda: ";
	cin >> serie;
	cout << endl << endl;

	return serie;
}

//  Esta función Filtra el array de objetos vídeos y muestra los episodios de una serie en particular
//  Para mostrar los episodios de una serie en particular, el usuario debe escribir el nombre 
//  de la serie que quiere, tal y como se muestra en las sugerencias y hacer enter.
void muestra_Filtro_Serie_Videos(Video *listaVideos[], int numObjetoV, Serie *listaSeries[], int numObjetoS)
{
	int exit;
	bool  presente;
	Episodio *unEpisodio;
	string serie, serieTmp;

	cout << "ESCRIBE EL NOMBRE DE LA SERIE PARA VER SUS EPISODIOS" << endl << endl;
	do
	{
		presente= false;
		serie = menuSerie(listaSeries, numObjetoS);

		if (serie !="0")
		{
			for ( int c = 0; c < numObjetoV; c++ )
			{
				if (typeid(*listaVideos[c]) == typeid(Episodio))
				{	
					unEpisodio = (Episodio *) listaVideos[c];
					serieTmp  = unEpisodio->getSerie();
					if (serieTmp == serie )
					{
						listaVideos[c]->mostrar();
						cout << "Temporada:    " << unEpisodio->getNumTemporada() << endl;
						cout << "Episodio:     " << unEpisodio->getNumEpisodio() << endl;
						cout << "Duración:     " << listaVideos[c]->getDuracion() << " minutos" << endl;
						cout << "Calificación: " << listaVideos[c]->getCalificacion() << "  estrellas"<< endl << endl;
						presente = true;
					}
				}
			}	
			// Dado que no se encuentre una serie con el nombre de las que se tienen
			// en catálogo, la función arroja este mensaje.
			if (presente != true)
				cout << "No se ha encontrado una serie con el término de búsqueda: " << endl << serie << endl << endl;
		}
		// Si el usuario escribe 0 este if, saca al usuario al menú principal.
		if (serie == "0")
			exit = 0;

	} while (exit !=0 );
}

// Esta función filtra el array de objetos vídeos  y muestra un menú de calificaciones 
// Filtra el array para películas con cierta calificación. El usuario escribe dígitos
// del 1 al 5. 
void muestra_Filtro_Rating_Pelicula(Video *listaVideos[], int numObjetoV)
{
	int calificacion, calificacionTmp;
	bool present;
	cout << "FILTRA PARA VER SOLO LAS MEJORES PELÍCULAS" << endl << endl;
	
	do
	{	
		present =  false;
		calificacion = menuRatings();
		cout << endl;

		for ( int c = 0; c < numObjetoV; c++ )
		{
			if (typeid(*listaVideos[c]) == typeid(Pelicula))
			{	
				calificacionTmp = listaVideos[c]->getCalificacion();
				if (calificacionTmp == calificacion )
				{
					listaVideos[c]->mostrar();
					cout << "Calificación: " << listaVideos[c]->getCalificacion() << endl << endl;
					present= true;
				}
			}
		}
		// Si el usuario escribe un número del 1 al 5 y la función no encuentra
		// películas de ese rating arroja este mensaje.
		if ( calificacion !=0 && calificacion <5 && calificacion >= 1 && present != true)
		{
			cout << "No se ha encontrado una película de calificacion: " << endl << calificacion << endl << endl << endl << endl;
		}
		// Si el usuario escribe un número fuera del 1 al 5, la función arroja el
		// siguiente mensaje. 
		if ( calificacion >5 || calificacion <0)
		{ 
			cout << "No existe esa calificación, prueba otra vez" << endl << endl << endl << endl;
		}
	} while( calificacion != 0); 
}

int main() 
{
	int opcionMenu, numObjetoV = 0, numObjetoS = 0;

	Video *listaVideos[30];
	Serie *listaSeries[10];
	
	carga_Datos_Videos( listaVideos, numObjetoV);
	carga_Datos_Series( listaSeries, numObjetoS);

	do
    {
		cout << endl;
        cout << "Menu de opciones " << endl;
        cout << endl;

		cout << "0) Salir" << endl;
        cout << "1) Mostrar la lista de películas" << endl;
        cout << "2) Mostrar la lista de series" << endl;
        cout << "3) Mostrar los videos en general con una cierta calificación" << endl;
		cout << "4) Mostrar los videos en general de un cierto género" << endl;
		cout << "5) Mostrar los episodios de una determinada serie con sus calificaciones"<< endl;
		cout << "6) Mostrar las películas con cierta calificación"<< endl;
        
		cout << "   Teclea el número: ";
        cin  >> opcionMenu;
        cout << endl;
		
		// Este es el menú principal del servicio simplificado de streaming
		// Son las  6 opciones que tiene el usuario para hacer dentro de Este
		// Escribir dígitos del 1 al 6, si 0 el programa cierra. 
        switch (opcionMenu) 
		{
            case 1:  { muestra_Lista_Peliculas(listaVideos,numObjetoV); break; }
                
            case 2:  { muestra_Lista_Series(listaSeries, numObjetoS); break; }

            case 3:  { muestra_Filtro_Rating_Videos(listaVideos, numObjetoV); break; }

            case 4:  { muestra_Filtro_Genre_Videos(listaVideos, numObjetoV); break; }
            
			case 5:  { muestra_Filtro_Serie_Videos(listaVideos, numObjetoV,listaSeries, numObjetoS); break; }			

            case 6:  { muestra_Filtro_Rating_Pelicula(listaVideos, numObjetoV); break; }                
        }

    } while (opcionMenu != 0);
}