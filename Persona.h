#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include<conio.h>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

class Persona {

public:

   // constructor clase Persona
   Persona( int = 0, string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "");

   // Funciones para obtener el ID
   void establecerId( int );
   int obtenerNumeroId() const;

   // Funciones para acceder a los datos privados
   void establecerApellido( string );
   string obtenerApellido() const;

   void establecerPrimerNombre( string );
   string obtenerPrimerNombre() const;

   void establecerTelefono( string );
   string obtenerTelefono() const;

   void establecerDpi( string );
   string obtenerDpi() const;

   void establecerEmail( string );
   string obtenerAula() const;

   void establecerFacultad( string );
   string obtenerFacultad() const;

   void establecerGenero( string );
   string obtenerGenero() const;

   void establecerDepartamento( string );
   string obtenerCodFacultad() const;

     void establecerCarrera( string );
   string obtenerCarrera() const;

     void establecerSede( string );
   string obtenerSede() const;

   //Funciones para el tratado de archivos
    void imprimirRegistro( fstream& );
    void actualizarRegistro( fstream& );
    void nuevoRegistro( fstream& );
    void eliminarRegistro( fstream& );
    void mostrarLinea( ostream&, const Persona & );
    int obtenerId( const char * const );
    void crearArchivoEmpleados();
    void consultarRegistro( fstream& );
    void busquedaRegistro(fstream&);
    void mostrarLineaPantalla( const Persona &);
    fstream inicioArchivo();





private:
   int numeroCUI;
   char apellido[ 15 ];
      char primerNombre[ 10 ];
      char telefono[ 9 ];
      char dpi[ 14 ];
      char codfacultad[21];
      char aula[31];
      char facultad[41];
      char genero[2];
      char carrera[33];
      char sede[36];

};

#endif
