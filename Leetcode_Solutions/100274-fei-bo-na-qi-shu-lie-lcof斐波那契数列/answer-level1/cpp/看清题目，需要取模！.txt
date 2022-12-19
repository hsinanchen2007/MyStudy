### 解题思路

用递归的方法很好理解，但实现n=100，远不如非递归方式，用temp0,temp1记录当前值和前一个记录，最后转变成俩数相加
### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        long result=0;
        long temp0=0,temp1=1;
        if(n<0)
        return -1;
        if(n==0)
        return 0;
        if(n==1)
       return 1;

        int i=n-1;
        while(i--)
        {
            result=(temp0+temp1)%1000000007;
            temp0=temp1;
            temp1=result;
        }
        return result;
    }
};
```