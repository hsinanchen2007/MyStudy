

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        int a = 0, b = 1, sum;
        for(int i = 0; i < n+1; i++){
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};
```