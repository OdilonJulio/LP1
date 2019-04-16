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
	
	/* adiciona elementos */
	conjuntoA.add(1);
	conjuntoA.add(3);
	conjuntoA.add(5);
	conjuntoA.add(7);
	conjuntoA.getElementos();
		
	conjuntoB.add(2);
	conjuntoB.add(4);
	conjuntoB.add(6);
	conjuntoB.add(8);
	conjuntoB.add(conjuntoA);
	conjuntoB.getElementos();
	
	cout << "\n\n\n" << endl;
	conjuntoC.add(conjuntoA + conjuntoB);
	conjuntoC.getElementos();

	return 0;
}