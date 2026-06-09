### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
    if(n<=3)
        return n-1;
    int sum;
    int a,b;
    if(n>3)
    {
        a = n/3;
        b = n%3;
        if(b==0) 
            sum = pow(3,a);
        else if(b==1)
            sum = pow(3,a-1)*4;
        else
            sum = pow(3,a)*b;  
    }
    return sum;
    }
};
```