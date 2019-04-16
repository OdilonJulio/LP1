#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_

#include <iostream>
#include <algorithm> // find
#include <vector>
using namespace std;

template<typename T>
class Conjunto{
	private:
		vector<T> elementos;
	public:
		Conjunto();
		//vector<T> getElementos();
		void add(T elemento_);
		void add(Conjunto<T> & conjunto_);
		void getElementos();
		int tamanho();
		bool busca(T elemento_);
		Conjunto<T> operator + (const Conjunto<T> & c1_);
		Conjunto<T> operator - (const Conjunto<T> & c1_);	
};

template<typename T>
Conjunto<T>::Conjunto(void){ 	}

/*
template<typename T>
vector<T> getElementos(){
	return elementos;
}
*/

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
Conjunto<T> Conjunto<T>::operator + (const Conjunto<T> & c1_){
	
	Conjunto<int> tmp;
	
	if ( c1_.tamanho() == 0 ){
		return tmp;
	}
	tmp.add(*this);
	for(int i = 0; i < c1_.tamanho(); i++){
		if( this->busca(c1_.elementos[i]) == false){
			tmp.add(c1_.elementos[i]);
		}
	}
	return tmp;
}

template<typename T>
Conjunto<T> Conjunto<T>::operator - (const Conjunto<T> & c1_){
	
	Conjunto<int> tmp;
	
	if ( c1_.tamanho() == 0 ){
		return this;
	}
	//tmp.add(*this);
	for(int i = 0; i < c1_.tamanho(); i++){
		if( this->busca(c1_.elementos[i]) == false ){
			if ( c1_.busca(c1_.elementos[i]) == false ){
				tmp.add(c1_.elementos[i]);
			}
		}
	}
	return tmp;
}






/*
SOBRECARREGAR

Operadores 

+ -> União de conjuntos; OK

- -> Diferença de conjuntos;

* -> Interseção;
*/





















#endif //_CONJUNTO_H_