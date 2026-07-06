#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long main_sum = 0;
    long long fraction_sum = 0;
    
    long long zxc; 
    char dot; 
    long long zxc2;
    
    while (cin >> zxc >> dot >> zxc2) {
        main_sum += zxc;
        fraction_sum += zxc2;
        main_sum += fraction_sum / 1000000000000000;
        fraction_sum %= 1000000000000000;
    }

    string final_frac = to_string(fraction_sum);
    while (final_frac.length() < 15){
        final_frac = "0" + final_frac;
    }
    cout << main_sum << dot << final_frac;

    return 0;
}