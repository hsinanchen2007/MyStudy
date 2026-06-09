题解如下：
```
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include <limits>

using namespace std;
#define ll long long

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        ll low = 0;
        ll high = x;
        ll mid = 0;
        ll fmid = -1;
        while (fmid != mid) {
            // cout << mid << endl;
            fmid = mid;
            mid = (low + high)/2;
            if (mid * mid - x > 0) {
                high = mid;
                continue;
            }
            if (mid * mid - x < 0) {
                low = mid;
                continue;
            }
        }
        // mid = (high + low)/2;
        return mid;
    }
};
```