### 解题思路
v[i] = min(v[i], v[i - j*j] + 1)
j 属于[1, sqrt(i)]


### 代码

```cpp
#include "math.h"
class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n+1, 0);
        int cur = (int) sqrt((float)n);
        for (int i = 1; i <= n; i++) {
            v[i] = i;
            for (int j = 1; i - j * j >= 0; j++) {
                v[i] = min(v[i], v[i - j * j] + 1);
            }
        }
        return v[n];

    }
};
```