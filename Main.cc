
# include "ArrayStack.h"
# include "assert.h"

int main()
{
    ArrayStack<int> s(10);
    // Verificar si esta inicialmente vacia
    assert(s.empty());
    s.push(2);
    // Verificar que no esta vacia ya que ingresamos 2
    assert(!s.empty());
    // Verificar si el ultimo elemento ingresado es 2
    assert(s.top() == 2);
    s.pop();
    // Una vez retiramos un elemento, verificar si esta vacia
    assert(s.empty());
    // s.push(12);
    // s.push(2);
    // s.push(19);
    return 0;
}
