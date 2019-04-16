#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
class Conjunto{
	private:
		vector<T> elementos;
	public:
		Conjunto();
		void add(T elemento_);
		void add(Conjunto<T> & conjunto_);
		void getElementos();
		int tamanho();
		bool busca(T elemento_);
		bool operator + (Conjunto<T> & c1_);	
};

template<typename T>
Conjunto<T>::Conjunto(void){ 	}

template<typename T>
void Conjunto<T>::add(T elemento_){
	this->elementos.push_back(elemento_);
}

template<typename T>
void Conjunto<T>::add(Conjunto<T> & conjunto_){
	for (auto &i : conjunto_.elementos){		
		this->elementos.push_back(i);
	}
}

template <typename T>
void Conjunto<T>::getElementos() {
	cout << "Elementos do Conjunto: [ ";
	for(auto &i : this->elementos) {
		cout << i << " ";
	}
	cout << "]" << endl;
}

template <typename T>
int Conjunto<T>::tamanho(){
	return this->elementos.size();
}

template <typename T>
bool Conjunto<T>::busca(T elemento_){
	for(auto &i : this->elementos) {
		if ( i == elemento_){
			return true;
		}
	}
	return false;
}

template<typename T>
bool Conjunto<T>::operator + (Conjunto<T> & c1_){
	if ( c1_.tamanho() == 0 ){
		return false;
	}
	for(int i = 0; i < c1_.tamanho(); i++){
		if( this->busca(c1_.elementos[i]) == false){
			this->add(c1_.elementos[i]);
		}
	}
	return true;
}

/*

SOBRECARREGAR

Operadores 

+ -> União de conjuntos;

- -> Diferença de conjuntos;

* -> Interseção;

*/





















#endif //_CONJUNTO_H_