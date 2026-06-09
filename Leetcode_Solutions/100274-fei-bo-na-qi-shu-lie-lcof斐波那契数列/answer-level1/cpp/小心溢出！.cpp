### 解题思路
long long都装不下

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        long long a=0,b=1,c;
        for(int i=1;i<n;i++)
        {
            c=(a+b)%1000000007;
            a=b;
            b=c;
        }
        return (int)c;
    }
};
```