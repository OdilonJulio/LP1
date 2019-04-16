#include <iostream>
#include <algorithm>
#include <vector>

#include "templateConjunto.h"

using namespace std;

int main(){
	/* Instanciando conjuntos. */
	Conjunto<int> conjuntoA;
	Conjunto<int> conjuntoB;
	Conjunto<int> conjuntoC;
	Conjunto<int> conjuntoD;
	
	/* adiciona elementos */
	conjuntoA.add(1);
	conjuntoA.add(3);
	conjuntoA.add(5);
	conjuntoA.add(7);
	conjuntoA.getElementos();
		
	conjuntoB.add(0);
	conjuntoB.add(3);
	conjuntoB.add(10);
	conjuntoB.add(30);
	conjuntoB.add(conjuntoA);
	conjuntoB.getElementos();
	
	cout << endl << endl;


	conjuntoC = conjuntoA + conjuntoB;
	conjuntoC.getElementos();
	
	cout << endl << endl;
	conjuntoD = conjuntoC - conjuntoA;
	conjuntoD.getElementos();
	return 0;
}