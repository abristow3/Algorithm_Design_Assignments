#include <iostream>

int divideAndConquerAlgo(int n, int &additionCount) {

    if (n > 3) {
        int x = divideAndConquerAlgo(n - 2, additionCount) + divideAndConquerAlgo(n - 1, additionCount) +
                divideAndConquerAlgo(n - 3, additionCount);
        additionCount += 2;
        return x;
    } else {
        return 1;
    }
}

int dynamicAlgo(int n, int &additionCount) {
    if (n > 3) {
        int x = 0;
        int x1 = 1;
        int x2 = 1;
        int x3 = 1;

        additionCount = 0;

        for (int i = 4; i < n + 1; i += 1) {
            x = x1 + x2 + x3;
            x3 = x2;
            x2 = x1;
            x1 = x;
            additionCount += 2;
        }
        return x;

    } else {
        return 1;
    }
}

int main() {
    //set vars
    int additionCount = 0;
    int n = 0;
    int user_input;

    std::cout << "Enter a number greater than 0: " << std::endl;
    std::cin >> user_input;
    n = user_input;

    // Divide and conquer algo
    int x = divideAndConquerAlgo(n, additionCount);
    std::cout << "===== DIVIDE AND CONQUER =====" << std::endl;
    std::cout << "=== The result of your input: " << n << ", was: " << x << " ===" << std::endl;
    std::cout << "=== " << additionCount << " addition operations performed. ===\n" << std::endl;

    // reset vards
    n = user_input;
    additionCount = 0;

    // Dyanmic Programmign code
    int y = dynamicAlgo(n, additionCount);
    std::cout << "===== DYNAMIC PROGRAMMING =====" << std::endl;
    std::cout << "=== The result of your input: " << n << ", was: " << y << " ===" << std::endl;
    std::cout << "=== " << additionCount << " addition operations performed. ===\n" << std::endl;

    //call each with n=5, 10, 15, 20, 25 and create table of values
    int nArray[] = {5, 10, 15, 20, 25};
    int divideArray[] = {};
    int dynamicArray[] = {};
    int divideAdditions, dynamicAdditions = 0;

    for (int i = 0; i < 5; i++) {
        n = nArray[i];

        int divx = divideAndConquerAlgo(n, divideAdditions);
        int dynx = dynamicAlgo(n, dynamicAdditions);

        // Update addition values in arrays
        divideArray[i] = divideAdditions;
        dynamicArray[i] = dynamicAdditions;

        // reset counts
        dynamicAdditions = 0;
        divideAdditions = 0;

    }
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "| n | Divide & Conquer Additions | Dynamic Programming Additions |" << std::endl;
    std::cout << "------------------------------------------------------------------\n" << std::endl;

    for (int i = 0; i < 5; i++){
        std::cout << "| " << nArray[i] << " | " << divideArray[i] << " | " << dynamicArray[i] << " |" << std::endl;
    }

    return 0;
}


