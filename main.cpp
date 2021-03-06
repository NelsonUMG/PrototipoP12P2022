#include <iostream>
#include<conio.h>
#include "Persona.h"
#include "Facultad.h"
#include "Usuario.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <ctime>
#include <vector>
#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;


//Declaracion de las funciones para abrir los menus
void consultas();
void gestionAlumno();


//inicio menu principal
int main(int argc, char *argv[])
{

int choice;
	char x;
	do
    {
	system("cls");
	//Funcion que imprime Fecha  y Hora
	cout<<"\t\t\t    SISTEMA DE CORPORACIÓN EDUCATIVA    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultas"<<endl;
	cout<<"\t\t\t 2. Gestion Alumnos"<<endl;
	cout<<"\t\t\t 3. Salir"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        //Se envia a la Bitacora la accion realizada por el usuario
        consultas();
		break;
	case 2:
        gestionAlumno();
		break;
	case 3:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 3);
    return 0;
}
//Declaracion menu consultas
void consultas()
{
    //Creacion de un objeto de la clase Persona
    Persona alumno;
    fstream alumnosEntradaSalida = alumno.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    CONSULTAS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Alumnos"<<endl;
	cout<<"\t\t\t 2. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        alumno.consultarRegistro(alumnosEntradaSalida);
		break;
	case 2:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	alumnosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 2);
}

void gestionAlumno()
{
    Persona alumno;

    fstream alumnosEntradaSalida = alumno.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    GESTION EMPLEADOS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Alumno"<<endl;
	cout<<"\t\t\t 2. Busqueda de Alumnoss"<<endl;
	cout<<"\t\t\t 3. Agregar Alumnos"<<endl;
	cout<<"\t\t\t 4. Modificar Alumnoss"<<endl;
	cout<<"\t\t\t 5. Eliminar Alumnos"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Alumnos"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        alumno.consultarRegistro(alumnosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        alumno.busquedaRegistro(alumnosEntradaSalida);
		break;
	case 3:
        alumno.nuevoRegistro(alumnosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
        alumno.actualizarRegistro(alumnosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:
        alumno.eliminarRegistro(alumnosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        alumno.imprimirRegistro(alumnosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		}
	alumnosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}

