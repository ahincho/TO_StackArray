
# include "ArrayStack.h"
# include "assert.h"
# include <iostream>

// Usar assert para poner precondiciones y postcondiciones en nuestro codigo

using namespace std;

// Segun contrato - push recibe un stack y un elemento T
// ingresa el elemento y retorna el mismo stack con todos
// los elementos anteriores y el nuevo elemento en el top

template <typename T>
void ArrayStack<T>::push(T e)
{
	// Debemos tener espacio para poder ingresar un elemento
	int numElem = sp - data;
	// Creo que es redundante ...
	assert(numElem < size);
	if (numElem == size)
	{
		// El compilador espera que resize() se haga en el paso de enlace
		// Por eso es que compilo sin arrojar un error
		resize();
	}
	*sp = e;
	sp++;
	// Recalculamos la cantidad de elementos ...
	numElem = sp - data;
	// Una vez hemos ingresado un elemento, no deberia
	// sobrepasar el limite que tiene nuestro array
	assert(numElem < size);
	// En caso se dispare 'assert' se detiene la ejecucion
	// Ahora ... debemos cumplir el contrato ... top() == e
	assert(top() == e);
	cout << "Todo bien al pushear ..." << endl;
};

// Segun contrato pop recibe un stack y remueve el top()

template <typename T>
void ArrayStack<T>::pop()
{
	// En vez de un if ... Podriamos usar un assert
	// De esta manera verificamos si no esta vacia
	assert(!empty());
	// En caso se dispare 'assert' se detiene la ejecucion
	sp--;
	// Calculamos cantidad de elementos
	int numElem = sp - data;
	// La pila puede quedar vacia pero no podemos
	// retirar mas elementos de los que tenemos
	assert(numElem >= 0);
	// En caso se dispare 'assert' se detiene la ejecucion
	cout << "Habian elementos ..." << endl;
}

// Segun contrato empty() recibe un stack y evalua
// si esta vacio, devuelve un valor booleano

template <typename T>
bool ArrayStack<T>::empty()
{
	// Creo que no hay mucho que evaluar ...
	int numElem = sp - data;
	return numElem == 0;
}

// Segun contrato, top() recibe un stack y devuelve
// el ultimo elemento que se ingreso en el stack

template <typename T>
T ArrayStack<T>::top()
{
	// En vez de usar un if podemos usar un assert
	// para verificar que el stack no esta vacio
	assert(!empty());
	return *(sp - 1);
}

template <typename T>
void ArrayStack<T>::resize()
{
	T newData[] = new T[size + FACTOR];
	for(int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	sp = data + size;
	size += FACTOR;
}

/*
int main()
{
	ArrayStack<int> s(10);
	return 0;
}
*/
