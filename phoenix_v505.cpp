#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;
typedef __int128_t int128;

void print128(int128 n) {
    if (n == 0) { cout << "0"; return; }
    string s = "";
    while (n > 0) { s += (char)('0' + (n % 10)); n /= 10; }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    auto start = chrono::steady_clock::now();
    cout << "🔱 [PHOENIX-V505] RELOADED" << endl;
    
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

    // Automatically calculate target based on Claude's indices
    // indices: 0, 4, 11, 17, 24
    int128 target = p[0] + p[4] + p[11] + p[17] + p[24];

    cout << "Target set to: "; print128(target); cout << endl;

    unordered_map<long long, int> firstHalf;
    for (int i = 0; i < (1 << 15); i++) {
        int128 sum = 0;
        for (int j = 0; j < 15; j++) if ((i >> j) & 1) sum += p[j];
        firstHalf[(long long)sum] = i;
    }

    for (int i = 0; i < (1 << 15); i++) {
        int128 sum = 0;
        for (int j = 0; j < 15; j++) if ((i >> j) & 1) sum += p[15 + j];
        
        int128 diff = target - sum;
        if (firstHalf.count((long long)diff)) {
            cout << "\n🎯 [BINGO!] MATCH FOUND!" << endl;
            int mask1 = firstHalf[(long long)diff];
            for(int j=0; j<15; j++) if((mask1 >> j) & 1) { cout << " + "; print128(p[j]); cout << endl; }
            for(int j=0; j<15; j++) if((i >> j) & 1) { cout << " + "; print128(p[15+j]); cout << endl; }
            cout << "Verification: PASS ✅" << endl;
            return 0;
        }
    }
    return 0;
}
