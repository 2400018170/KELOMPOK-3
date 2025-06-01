#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <limits>  
using namespace std;

struct Bioskop {
  string nama;
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
