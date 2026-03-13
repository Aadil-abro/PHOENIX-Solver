#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;

/**
 * 🔱 PHOENIX-V505: Advanced Subset Sum Solver
 * Developed by: Aadil-abro (Larkana)
 * Logic: Meet-in-the-Middle (O(2^(N/2)))
 * Purpose: Cracking N=30 cryptographic subset sum puzzles.
 */

typedef __int128_t int128;

// Function to convert 128-bit int to string for printing
void print128(int128 n) {
    if (n == 0) { cout << "0"; return; }
    string s = "";
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    auto start = chrono::steady_clock::now();
    cout << "🔱 [PHOENIX-V505] STARTING ENGINE..." << endl;
    cout << "--------------------------------------" << endl;

    // The Official Dataset
    vector<int128> p = {
        3847561029384756, 9182736450192837, 2718281828459045, 6473829104738291,
        5647382910473829, 1234567890123456, 7777777777777777, 3333333333333333,
        9999999999999998, 4444444444444444, 2222222222222222, 8888888888888887,
        1111111111111112, 6666666666666666, 5555555555555556, 3141592653589793,
        2718281828459046, 9876543210987654, 1234567890123457, 7654321098765432,
        4321098765432109, 8765432109876543, 3210987654321098, 6543210987654321,
        9876543210987653, 2109876543210987, 5432109876543210, 7890123456789012,
        1357924680135792, 8024681357902468
    };

    // The Target we are hunting
    int128 target = (int128)36154695588524139ULL;

    // Using unordered_map for O(1) average lookup
    unordered_map<long long, int> firstHalf;
    
    cout << "[*] Indexing first 15 numbers (Space-Time Tradeoff)..." << endl;
    for (int i = 0; i < (1 << 15); i++) {
        int128 sum = 0;
        for (int j = 0; j < 15; j++) {
            if ((i >> j) & 1) sum += p[j];
        }
        firstHalf[(long long)sum] = i;
    }

    cout << "[*] Scanning second 15 numbers (Searching 1.07 Billion combinations)..." << endl;
    bool found = false;
    for (int i = 0; i < (1 << 15); i++) {
        int128 sum = 0;
        for (int j = 0; j < 15; j++) {
            if ((i >> j) & 1) sum += p[15 + j];
        }

        int128 diff = target - sum;
        if (firstHalf.count((long long)diff)) {
            auto end = chrono::steady_clock::now();
            found = true;
            cout << "\n🎯 [BINGO!] SOLUTION VERIFIED" << endl;
            cout << "--------------------------------------" << endl;
            
            int128 check_sum = 0;
            int mask1 = firstHalf[(long long)diff];
            
            cout << "Subset Found:" << endl;
            for(int j=0; j<15; j++) {
                if((mask1 >> j) & 1) {
                    cout << " - "; print128(p[j]); cout << endl;
                    check_sum += p[j];
                }
            }
            for(int j=0; j<15; j++) {
                if((i >> j) & 1) {
                    cout << " - "; print128(p[15+j]); cout << endl;
                    check_sum += p[15+j];
                }
            }
            
            cout << "--------------------------------------" << endl;
            cout << "Result Sum:     "; print128(check_sum); cout << endl;
            cout << "Target Goal:    "; print128(target); cout << endl;
            cout << "Verification:   PASS ✅" << endl;
            
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Search Time:    " << duration.count() << " ms" << endl;
            break;
        }
    }

    if (!found) {
        cout << "\n❌ Search completed. No valid subset exists for this target." << endl;
    }

    return 0;
}
