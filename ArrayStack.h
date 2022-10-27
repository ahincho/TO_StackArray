
# ifndef ARRAY_STACK_H
# define ARRAY_STACK_H

# include "Stack.h"

# define FACTOR 10

template <typename T>
class ArrayStack: public Stack<T>
{
	private:
		// Error: flexible array member 'ArrayStack<int>::data' not at end of 'class ArrayStack<int>'
		T* data; // Elements
		int size; // Memory size
		T* sp; // Stack pointer
		void resize();
	public:
		ArrayStack(int s): size { s }, data { new T[size] }, sp { data } {}
		void push(T);
		void pop();
		T top();
		bool empty();
};

# endif

