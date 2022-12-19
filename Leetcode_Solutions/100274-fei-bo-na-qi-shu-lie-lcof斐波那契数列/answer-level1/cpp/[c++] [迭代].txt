### 解题思路
迭代

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int res;
        int a=0,b=1;
        for(int i=0;i<n-1;i++){
            res=(a+b)%1000000007;
            a=b;
            b=res;
        }
        return res;
    }
};
```