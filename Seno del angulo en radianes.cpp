#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

float CalcularSeno(int x, int rep);
float CalcularCoseno (int x, int rep);
float CalcularLogna(int x, int rep);
float potencia(float x, float r);
float factorial (float cont);

int main ()
{
	int opc; // se guarda aquí la opción para el menú.
	int x; // Se guarda el valor del ángulo que el usuario ingrese.
	int rep; // Número de repeticiones de la serie que hará el programa.
	
	cout << "El presente programa calcula la aproximacion del angulo de seno, coseno o logaritmo natural en radianes.\nPor favor elige una de las "<<
	"siguientes opciones: " << endl << endl;
	do
	{
		system("cls");	
		cout << "1.- Calcular seno de x." << endl;
		cout << "2.- Calcular coseno de x." << endl;
		cout << "3.- Calcular logaritmo natural de x." << endl;
		cout << "0.- Salir de la aplicacion." << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Opcion: ";
		cin >> opc;
		
		system("cls");
		
		switch (opc)
		{
			case 1: cout << "\n\t-----Bienvenido!!-----" << endl;
					cout << "\n\tIngresa el valor de x: ";
					cin >> x;
					cout << "\tCuantas veces deseas repetir la serie?: ";
					cin >> rep;
					cout << "\tEl seno del angulo " << x << " es: " << CalcularSeno(x, rep);
					break; 
			
			case 2: cout << "\n\t-----Bienvenido!!-----" << endl;
					cout << "\n\tIngresa el valor de x: ";
					cin >> x;
					cout << "\tCuantas veces deseas repetir la serie?: ";
					cin >> rep;
					cout << "\tEl coseno del angulo " << x << " es: " << CalcularCoseno(x, rep);
					break;
			case 3: cout << "\n\t-----Bienvenido!!-----" << endl;
					cout << "\n\tIngresa el valor de x: ";
					cin >> x;
					cout << "\tCuantas veces deseas repetir la serie?: ";
					cin >> rep;
					cout << "\tEl Logaritmo natural del angulo " << x << " es: " << CalcularLogna(x, rep);
					break;
			default: if (opc != 0)
					 {
						cout << "\n\tEsa opcion no es valida, intenta de nuevo!" << endl;
					 }
					 else
					 	cout << "Doble enter para salir.";
		}
		getch();	
	}while(opc != 0);
	
	return 0;
}

float CalcularSeno(int x, int rep)
{
	float suma = 0;
	for (int i = 1; i <= rep; i++)
	{
		if (i % 2 != 0)
			suma+= ((float)potencia(x, i*2.0-1) / factorial (i * 2.0 - 1));
		else 
			suma-= ((float)potencia(x, i*2.0-1) / factorial (i * 2.0 - 1));
	}
	return suma;
}

float CalcularCoseno (int x, int rep)
{
	float suma = 0;
	float signo = -1.0;
	for (int i = 0; i < rep; i++)
	{
		if (i % 2 == 0)
			suma+= ((float)potencia(x, i*2.0) / factorial (i*2.0));
		else
			suma-= ((float)potencia(x, i*2.0) / factorial (i*2.0));
	}
	return suma;
}

float CalcularLogna(int x, int rep)
{
	float sum = 0;
	for (int i = 1; i <= rep; i++)
		sum+= (1.0/i)*potencia( (x-1.0) / (x), i);
	return sum;
}

float potencia (float x, float r)
{
	float n = 1;
	for (int i = 1; i <= r; i++)
		n*=x;
	return n;
}

float factorial (float cont)
{
	int fact = 1;
	if (cont == 0)
		return 1;
	else
	{
		for (int i = 1; i <= cont; i++)
			fact *= i;
	}
	return fact;
}
