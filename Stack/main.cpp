#include <iostream>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    Stack<int> A(4);
    A[0] = 3;
    A[1] = 4;
    A[2] = 5;
    A[3] = 6;
    
    
    std::cout << A[0] << " " << A[1] << std::endl;
    
    Stack<int> B(A);
    
    std::cout << B[2] << " " << B[3] << std::endl;
    
    return 0;
}
