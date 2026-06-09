
### 代码

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        int limit = n;
        for(int i = 1; i <= limit; i++) {
            n -= i;
            
            if(n < 0) {
                res = i - 1;
                break;
            } 

            if(0 == n) {
                res = i;
                break;
            }
        }

        return res;
    }
};
```