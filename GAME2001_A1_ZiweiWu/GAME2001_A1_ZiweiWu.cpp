#include <iostream>
#include "BaseArray.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"

using namespace std;

int main() {
    cout << "Output of ordered array: " << endl;
    OrderedArray<int> orderedArray(10);
    orderedArray.push(2);
    orderedArray.push(10);
    orderedArray.push(5);
    orderedArray.push(9);
    orderedArray.push(63);
    for (int i = 0; i < orderedArray.GetSize(); i++)
        cout << orderedArray[i] << " ";
    cout << endl << endl;
    cout << "I am going to push an already existed (10) in the array to the array again " << endl;
    orderedArray.push(10);
    cout << "Output of new ordered array: " << endl;
    for (int i = 0; i < orderedArray.GetSize(); i++) {
        cout << orderedArray[i] << " ";
    }
    cout << endl;
    cout << "Notice there is only one 10 in the above array" << endl;

    cout << "\nOutput of unordered array: " << endl;
    UnorderedArray<int> unorderedArray(5);
    unorderedArray.push(2);
    unorderedArray.push(10);
    unorderedArray.push(5);
    unorderedArray.push(9);
    unorderedArray.push(63);
    for (int i = 0; i < unorderedArray.GetSize(); i++)
        cout << unorderedArray[i] << " ";
    return 0;
}
