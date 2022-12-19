### 解题思路
终于遇到一道简单题啊啊啊
奥利给！

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
    
    int t,mul,sum,rst;
    mul=1;sum=0;
    do{
        t=n%10;
        mul*=t;
        sum+=t;
        n/=10;
    }while(n>0);
    
    rst=mul-sum;
    return rst;

    }
};
```