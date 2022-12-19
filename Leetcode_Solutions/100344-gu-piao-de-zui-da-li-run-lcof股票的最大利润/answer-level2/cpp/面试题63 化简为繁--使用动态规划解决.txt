


```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0,
            b = INT_MIN;
        for (int i:prices) {
            a = max(a, b+i);
            b = max(b, -i);
        }
        return a;
    }
};
```