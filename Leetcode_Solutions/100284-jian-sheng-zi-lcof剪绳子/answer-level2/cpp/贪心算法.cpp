### 解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        //贪心算法
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n % 3 == 1)
        {
            return pow(3,n / 3 -1) * 2 * 2;
        }else if(n % 3 == 2)
        {
            return pow(3,n / 3) * 2;
        }
        else
        {
            return pow(3,n / 3);
        }
        return 0;
    }
};
```