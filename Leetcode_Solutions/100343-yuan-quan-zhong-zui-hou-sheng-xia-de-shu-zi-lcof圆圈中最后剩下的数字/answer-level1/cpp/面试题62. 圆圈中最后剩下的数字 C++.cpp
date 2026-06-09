### 解题思路
f(n, m)表示在n个数字0,1,...,n-1中删除第m个数字后剩下的数字，用f`(n - 1, m)表示
即f(n, m) = f`(n - 1, m)

f`(n - 1, m) = (f(n - 1, m) + k + 1) % n
             = (f(n - 1, m) + m ) % n
f(n , m) = (f(n - 1, m) + m) % n

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        // if(n < 1 || m < 1){
        //     return -1
        // }
        int last = 0;   // 当n为1的时候，结果总为0
        // 当n = 2时，i = 2
        for(int i = 2; i <= n; ++i){
            last = (last + m) % i;
        }
        return last;
    }
};
```