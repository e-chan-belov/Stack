#include <iostream>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    Stack<int> A(4);
    A[0] = 0;
    A[1] = 1;
    A[2] = 2;
    A[3] = 3;
    
    
    std::cout << A[0] << " " << A[1] << std::endl;
    
    Stack<int> B(A);
    
    std::cout << B[2] << " " << B[3] << std::endl;
    
    std::cout << B.add(10) << std::endl;
    
    return 0;
}
