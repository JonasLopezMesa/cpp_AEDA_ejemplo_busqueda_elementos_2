#include "Clases.h"

int main () {

	int x;
	cout << "1" << endl;
	char r[] = "archivo.txt";
	cin >> r;
	cout << "2" << endl;
	sll lista;
	cout << "3" << endl;
	lista.read(r);
	cout << "4" << endl;
	lista.imprimir();
	cout << "introduzca el elemento que quiera buscar" << endl;
	cin >> x;
	lista.buscar(x);
	
	
	
	return 0;
	
}
