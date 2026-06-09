### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int last=0;
        for(int i=2 ; i<=n ; i++)
        {
            last = (last+m) % i;
        }
        return last;
    }
};
```
//公式推导之后，得出最优数学解，环的重定位