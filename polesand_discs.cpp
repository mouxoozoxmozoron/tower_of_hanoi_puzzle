#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to perform the iterative Tower of Hanoi solution
int iterativeTowerOfHanoi(int num_disks, int source, int target, int auxiliary) {
    if (num_disks == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return 1;
    } else {
        int moves = iterativeTowerOfHanoi(num_disks - 1, source, auxiliary, target);
        cout << "Move disk " << num_disks << " from " << source << " to " << target << endl;
        moves += 1;
        moves += iterativeTowerOfHanoi(num_disks - 1, auxiliary, target, source);
        return moves;
    }
}

// Function to solve Tower of Hanoi using the general formula
void formulaTowerOfHanoi(int num_disks, int num_poles) {
    int total_moves = pow(2, num_disks) - 1;
    cout << "Minimum moves using general formula: " << total_moves << endl;
}

int main() {
    int num_disks, num_poles;

    cout << "Enter the number of disks: ";
    cin >> num_disks;

    cout << "Enter the number of poles: ";
    cin >> num_poles;

    // Measure execution time for iterative method
    auto start_iterative = high_resolution_clock::now();
    int iterative_moves = iterativeTowerOfHanoi(num_disks, 1, 3, 2); // Assuming 3 poles for simplicity
    auto stop_iterative = high_resolution_clock::now();
    auto duration_iterative = duration_cast<microseconds>(stop_iterative - start_iterative);
    cout << "Execution time for iterative method: " << duration_iterative.count() << " microseconds" << endl;
    cout << "Total moves for iterative method: " << iterative_moves << endl;

    // Measure execution time for using the general formula
    auto start_formula = high_resolution_clock::now();
    formulaTowerOfHanoi(num_disks, num_poles);
    auto stop_formula = high_resolution_clock::now();
    auto duration_formula = duration_cast<microseconds>(stop_formula - start_formula);
    cout << "Execution time for using general formula: " << duration_formula.count() << " microseconds" << endl;

    return 0;
}



//compillation 
//g++ -o polesand_discs polesand_discs.cpp
//./polesand_discs
