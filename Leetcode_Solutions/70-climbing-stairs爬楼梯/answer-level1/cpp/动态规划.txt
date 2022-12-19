### 解题思路
int tmp = 0;设在for外面提高效率

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int tmp1 = 1, tmp2 = 2;
        int tmp = 0;
        for(int i = 3; i <= n; i++){
            tmp = tmp2;
            tmp2 += tmp1;
            tmp1 = tmp;
        }
        return tmp2;
    }
};
```