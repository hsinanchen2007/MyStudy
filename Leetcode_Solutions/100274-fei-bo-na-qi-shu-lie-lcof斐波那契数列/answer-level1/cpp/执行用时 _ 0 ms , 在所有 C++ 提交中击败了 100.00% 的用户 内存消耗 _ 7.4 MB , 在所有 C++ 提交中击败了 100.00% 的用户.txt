### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        int sum=0;int a=0;int b=1;
        if(n==0)
            sum=0;
        if(n==1)
            sum=1;
        for(int i=1;i<n;i++)
        {
            sum=(a+b)%(1000000007);
            a=b;b=sum;
        }
        return sum;
    }
};
```