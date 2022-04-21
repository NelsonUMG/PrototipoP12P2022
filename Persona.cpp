#include "Persona.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>



// constructor Persona
   Persona::Persona( int valorNumeroCUI,
   string valorApellido, string valorPrimerNombre,
   string valorDpi, string valorFacultad, string valorTelefono, string valorAula,
   string valorCodFacultad, string valorCarrera, string valorSede, string valorGenero)
{
   establecerCUI( valorNumeroCUI );
   establecerApellido( valorApellido );
   establecerPrimerNombre( valorPrimerNombre );
   establecerTelefono( valorTelefono );
   establecerAula(valorAula);
   establecerFacultad(valorFacultad);
   establecerCodFacultad(valorCodFacultad);
   establecerGenero(valorGenero);
   establecerDpi( valorDpi );
   establecerCarrera( valorCarrera );
   establecerSede(valorSede);

}

// obtener el valor del ID
int Persona::obtenerNumeroCUI() const
{
   return numeroCUI;

}

// establecer el valor del ID
void Persona::establecerCUI( int valorNumeroCUI )
{
   numeroCUI = valorNumeroCUI;

}

// obtener el valor del apellido
string Persona::obtenerApellido() const
{
   return apellido;

}

// establecer el valor del apellido
void Persona::establecerApellido( string apellidoString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorApellido = apellidoString.data();
   int longitud = strlen( valorApellido );
   longitud = ( longitud < 15 ? longitud : 14 );
   strncpy( apellido, valorApellido, longitud );

   // anexar caracter nulo al apellido
   apellido[ longitud ] = '\0';

}

// obtener el valor del primer nombre
string Persona::obtenerPrimerNombre() const
{
   return primerNombre;

}

// establecer el valor del primer nombre
void Persona::establecerPrimerNombre( string primerNombreString )
{

   const char *valorPrimerNombre = primerNombreString.data();
   int longitud = strlen( valorPrimerNombre );
   longitud = ( longitud < 10 ? longitud : 9 );
   strncpy( primerNombre, valorPrimerNombre, longitud );


   primerNombre[ longitud ] = '\0';

}

string Persona::obtenerTelefono() const
{
   return telefono;

}


void Persona::establecerTelefono( string telefonoString )
{

   const char *valorTelefono = telefonoString.data();
   int longitud = strlen( valorTelefono );
   longitud = ( longitud < 9 ? longitud : 8 );
   strncpy( telefono, valorTelefono, longitud );


   telefono[ longitud ] = '\0';

}

string Persona::obtenerDpi() const
{
   return dpi;

}


void Persona::establecerDpi( string dpiString )
{

   const char *valorDpi = dpiString.data();
   int longitud = strlen( valorDpi );
   longitud = ( longitud < 15 ? longitud : 14 );
   strncpy( dpi, valorDpi, longitud );


   dpi[ longitud ] = '\0';

}


string Persona::obtenerCodFacultad() const
{
   return codfacultad;

}

void Persona::establecerCodFacultad( string codfacultadString )
{

   const char *valorCodFacultad = codfacultadString.data();
   int longitud = strlen( valorCodFacultad );
   longitud = ( longitud < 22 ? longitud : 21 );
   strncpy( codfacultad, valorCodFacultad, longitud );

   codfacultad[ longitud ] = '\0';

}

string Persona::obtenerAula() const
{
   return aula;

}


void Persona::establecerAula( string aulaString )
{

   const char *valorAula = aulaString.data();
   int longitud = strlen( valorAula );
   longitud = ( longitud < 32 ? longitud : 31 );
   strncpy( aula, valorAula, longitud );


   aula[ longitud ] = '\0';

}

string Persona::obtenerFacultad() const
{
   return facultad;

}


void Persona::establecerFacultad( string facultadString )
{

   const char *valorFacultad = facultadString.data();
   int longitud = strlen( valorFacultad );
   longitud = ( longitud < 41 ? longitud : 40 );
   strncpy( facultad, valorFacultad, longitud );


   facultad[ longitud ] = '\0';

}

string Persona::obtenerGenero() const
{
   return genero;

}


void Persona::establecerGenero( string generoString )
{

   const char *valorGenero = generoString.data();
   int longitud = strlen( valorGenero );
   longitud = ( longitud < 3 ? longitud : 2 );
   strncpy( genero, valorGenero, longitud );


   genero[ longitud ] = '\0';

}
string Persona:: obtenerCarrera () const
{
    return carrera;
}
void Persona:: establecerCarrera (string carreraString)
{
    const char *valorCarrera = carreraString.data();
    int longitud = strlen (valorCarrera);
    longitud = (longitud < 33 ? longitud: 32);
    strncpy( carrera, valorCarrera, longitud);

    carrera [ longitud ] = '\0';
}
string Persona::obtenerSede() const
{
   return sede;

}


void Persona::establecerSede( string sedeString )
{

   const char *valorSede = sedeString.data();
   int longitud = strlen( valorSede );
   longitud = ( longitud < 35 ? longitud : 34 );
   strncpy( sede, valorSede, longitud );


   sede[ longitud ] = '\0';

}


// crear archivo de texto con formato para imprimirlo
void Persona::imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "imprimir.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   }

   archivoImprimirSalida << left << setw( 10 ) << "CUI" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre"
       << setw( 14 ) << "Dpi" <<setw( 21 )<<"Codigo de Facultad"<<setw( 31 )<<"Aula"
       <<setw( 9 )<<"Telefono"<<setw( 10 )<<"Zona"<<setw( 5 )<<"Genero"<<setw( 36 )<<"Sede"<<setw( 33 )<<"Carrera"
       <<setw( 41 )<<"Facultad"<<endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona alumno;
   leerDeArchivo.read( reinterpret_cast< char * >( &alumno ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( alumno.obtenerNumeroCUI() != 0 )
         mostrarLinea( archivoImprimirSalida, alumno );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &alumno ),
         sizeof( Persona ) );

   }

}

// actualizar el saldo en el registro
void Persona::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de CUI a actualizar
   int numeroCUI = obtenerNumeroCUI( "Escriba el CUI del alumno a modificar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroCUI - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona alumno;
   actualizarArchivo.read( reinterpret_cast< char * >( &alumno ),
      sizeof( Persona ) );
    int choice;
   // actualizar el registro
   if ( alumno.obtenerNumeroCUI() != 0 ) {

  cout << left << setw( 10 ) << "CUI" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre"
       << setw( 14 ) << "Dpi" <<setw( 21 )<<"Codigo de Facultad"<<setw( 31 )<<"Aula"
       <<setw( 9 )<<"Telefono"<<setw( 10 )<<"Zona"<<setw( 5 )<<"Genero"<<setw( 36 )<<"Sede"<<setw( 33 )<<"Carrera"
       <<setw( 41 )<<"Facultad"<<endl;
   mostrarLinea( cout, alumno );

      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. Codigo facultad"<<endl;
	  cout<<"2. Telefono"<<endl;
	  cout<<"3. Facultad"<<endl;
	  cout<<"4. Sede"<<endl;
	  cout<<"5. Carrera"<<endl;
	  cout<<"6. Cancelar"<<endl;
	  cin >> choice;
    switch(choice)
    {
        case 1:
            //cambio de codigo de facultad
            {cout << "Ingrese el nuevo codigo facultad: "<<endl;
            string cambioCodFacul;
            cin >> cambioCodFacul;
            alumno.establecerCodFacultad( cambioCodFacul );}
            break;
        case 2:
            //cambio de telefono
            {cout << "Ingrese el nuevo telefono: "<<endl;
            string cambioTel;
            cin >> setw( 9 )>> cambioTel;
            alumno.establecerTelefono( cambioTel );}
            break;
        case 3:
            {cout << "Ingrese la nueva facultad: "<<endl;
            string cambioFacultad;
            cin >> cambioFacultad;
            alumno.establecerFacultad( cambioFacultad );}
            break;
        case 4:
            {cout << "Ingrese la nueva sede: "<<endl;
            string cambioSede;
            cin >> cambioSede;
            alumno.establecerSede( cambioSede );}
            break;
        case 5:
            {cout << "Ingrese la nueva Carrera: "<<endl;
            string cambioCarrera;
            cin >> cambioCarrera;
            alumno.establecerCarrera( cambioCarrera );}
            break;
        case 6:
            cout << "Modificacion cancelada, alumno sin cambios: "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

      cout << left << setw( 10 ) << "CUI" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre"
       << setw( 14 ) << "Dpi" <<setw( 21 )<<"Codigo de Facultad"<<setw( 31 )<<"Aula"
       <<setw( 9 )<<"Telefono"<<setw( 10 )<<"Zona"<<setw( 5 )<<"Genero"<<setw( 36 )<<"Sede"<<setw( 33 )<<"Carrera"
       <<setw( 41 )<<"Facultad"<<endl;
   mostrarLinea( cout, alumno );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroCUI - 1 ) * sizeof( Persona ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &alumno ),
         sizeof( Persona ) );

   }

   // mostrar error si el ID no existe
   else
      cerr << "El CUI #" << numeroCUI
         << " Aun no existe" << endl;

}

// crear e insertar registro
void Persona::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de ID a crear
   int numeroCUI = obtenerNumeroCUI( "Ingrese el CUI del nuevo Alumno: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroCUI - 1 ) * sizeof( Persona ) );

   // leer el registro del archivo
   Persona alumno;
   insertarEnArchivo.read( reinterpret_cast< char * >( &alumno ),
      sizeof( Persona ) );

   // crear el registro, si éste no existe ya
   if ( alumno.obtenerNumeroCUI() == 0 ) {

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

      // el usuario introduce los datos
      cout << "Escriba el apellido : " << endl;
      cin >> setw( 15 ) >> apellido;
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 10 ) >> primerNombre;
      cout << "Escriba el DPI: "<<endl;
      cin >> setw( 14 ) >> dpi;
      cout << "Escriba la Facultad: "<<endl;
      cin >> setw(21)>> codfacultad;
      cout << "Escriba el aula: "<<endl;
      cin >> setw(31)>> aula;
      cout << "Escriba el telefono: " << endl;
      cin >> setw( 9 ) >> telefono;
      cout << "Escriba la Zona: "<<endl;
      cin >> setw(3)>> facultad;
      cout << "Escriba el genero M/F: "<<endl;
      cin >> setw(2)>> genero;
      cout << "Escriba la Carrera: "<<endl;
      cin >> setw(33)>> carrera;
      cout << "Escriba la Sede: "<<endl;
      cin >> setw(36)>> sede;
      cout << "Escriba la facultad "<<endl;
      cin >> setw(41)>> facultad;

      // usar valores para llenar los valores del empleado
      alumno.establecerApellido( apellido );
      alumno.establecerPrimerNombre( primerNombre );
      alumno.establecerDpi( dpi );
      alumno.establecerTelefono( telefono );
      alumno.establecerCUI( numeroCUI );
      alumno.establecerFacultad(facultad);
      alumno.establecerAula(aula);
      alumno.establecerCodFacultad(codfacultad);
      alumno.establecerGenero(genero);
       alumno.establecerCarrera(carrera);
        alumno.establecerSede(sede);

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroCUI - 1 ) *
         sizeof( Persona ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &alumno ),
         sizeof( Persona ) );

   }
   else
      cerr << "El CUI numero #" << numeroCUI
           << " ya está registrado." << endl;

}

// eliminar un registro existente
void Persona::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de ID a eliminar
   int numeroCUI = obtenerNumeroCUI( "Escriba el CUI del alumno a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroCUI - 1 ) * sizeof( Persona ) );

   // leer el registro del archivo
   Persona alumno;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &alumno ),
      sizeof( Persona ) );

   // eliminar el registro, si es que existe en el archivo
   if ( alumno.obtenerNumeroCUI() != 0 ) {
      Persona alumnoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroCUI - 1 ) *
         sizeof( Persona ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &alumnoEnBlanco ),
         sizeof( Persona ) );

      cout << "El alumno con CUI #" << numeroCUI << " eliminado.\n";

   }

   else
      cerr << "No existe ningun alumno con el CUI #" << numeroCUI<<endl;

}
//Consulta de los empleados
void Persona::consultarRegistro( fstream &leerDeArchivo )
{

    cout << left << setw( 10 ) << "CUI" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre"
       << setw( 14 ) << "Dpi" <<setw( 21 )<<"Codigo de Facultad"<<setw( 31 )<<"Aula"
       <<setw( 9 )<<"Telefono"<<setw( 10 )<<"Zona"<<setw( 5 )<<"Genero"<<setw( 36 )<<"Sede"<<setw( 33 )<<"Carrera"
       <<setw( 41 )<<"Facultad"<<endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona alumno;
   leerDeArchivo.read( reinterpret_cast< char * >( &alumno ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( alumno.obtenerNumeroCUI() != 0 )
         mostrarLineaPantalla(alumno);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &alumno ),
         sizeof( Persona ) );

   }

}

// mostrar registro individual
void Persona::mostrarLinea( ostream &salida, const Persona &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroCUI()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 14 ) << registro.obtenerDpi().data()
          << setw( 21 ) << registro.obtenerCodFacultad().data()
          << setw( 31 ) << registro.obtenerAula().data()
          << setw( 9 ) << registro.obtenerTelefono().data()
          << setw( 41 ) << registro.obtenerFacultad().data()
          << setw( 2 ) << registro.obtenerGenero().data()
          << setw( 36 ) << registro.obtenerSede().data()
          << setw( 33 ) << registro.obtenerCarrera().data()<<endl;


}
void Persona::mostrarLineaPantalla( const Persona &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroCUI()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 14 ) << registro.obtenerDpi().data()
          << setw( 21 ) << registro.obtenerCodFacultad().data()
          << setw( 31 ) << registro.obtenerAula().data()
          << setw( 9 ) << registro.obtenerTelefono().data()
          << setw( 41 ) << registro.obtenerFacultad().data()
          << setw( 2 ) << registro.obtenerGenero().data()
          << setw( 36 ) << registro.obtenerSede().data()
          << setw( 33 ) << registro.obtenerCarrera().data()<<endl;
}
// obtener el valor del número ID del usuario

int Persona::obtenerNumeroCUI( const char * const indicador )
{
   int numeroCUI;

   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numeroCUI;

   } while ( numeroCUI < 1 || numeroCUI > 1000 );

   return numeroCUI;

}
void Persona::crearArchivoAlumnos()
{
    ofstream alumnosSalida( "alumnos.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !alumnosSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   }

   // crear espacios sin informacion
   Persona alumnoEnBlanco;

   for ( int i = 0; i < 1000; i++ )
      alumnosSalida.write(
         reinterpret_cast< const char * >( &alumnoEnBlanco ),
         sizeof( Persona ) );
}

fstream Persona::inicioArchivo(){
    Persona alumno;
        fstream alumnosEntradaSalida( "alumnos.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
    if ( !alumnosEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      alumno.crearArchivoAlumnos();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    return alumnosEntradaSalida;
}

//Funcion para encontrar empleado especifico
void Persona::busquedaRegistro(fstream &actualizarArchivo)
{
//Se obtiene el CUI a buscar
       int numeroCUI = obtenerNumeroCUI( "Escriba el CUI del alumno a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroCUI - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona alumno;
   actualizarArchivo.read( reinterpret_cast< char * >( &alumno ),
      sizeof( Persona ) );
if ( alumno.obtenerNumeroCUI() != 0 ) {
      //MOstrar la informacion obtenida
     cout << left << setw( 10 ) << "CUI" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre"
       << setw( 14 ) << "Dpi" <<setw( 21 )<<"Codigo de Facultad"<<setw( 31 )<<"Aula"
       <<setw( 9 )<<"Telefono"<<setw( 10 )<<"Zona"<<setw( 5 )<<"Genero"<<setw( 36 )<<"Sede"<<setw( 33 )<<"Carrera"
       <<setw( 41 )<<"Facultad"<<endl;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroCUI - 1 ) * sizeof( Persona ) );

   }

   // mostrar error si el ID no existe
   else
      cerr << "El CUI #" << numeroCUI
         << " aun no existe" << endl;

}
