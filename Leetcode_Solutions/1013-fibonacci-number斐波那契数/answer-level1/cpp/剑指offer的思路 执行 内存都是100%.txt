### 解题思路
剑指offer的思路

### 代码

```cpp
class Solution {
public:
    int fib(int N) {
        int array[2]={0,1};
         if(N<2) 
            return array[N];
        long long fibsmall=0;
        long long fibbig=1;
        long long fibN=0;
        for(int i=2;i<=N;i++)
        {
            fibN=fibsmall+fibbig;           
            fibsmall=fibbig;
            fibbig=fibN;
        }
        return fibN;
    }

    

    
};
```