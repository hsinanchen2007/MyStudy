### 解题思路
闭着眼睛写

### 代码

```cpp
class Solution {
public:
    int fib(int N) {
        if(N < 2)
        {
            return N;
        }
        int res = 0;
        int first = 0;
        int second = 1;
        for(int i = 2;i <= N;i++)
        {
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
};
```