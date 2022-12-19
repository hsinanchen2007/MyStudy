### 解题思路
代码思路：从n的二进制数的最低位开始，按位检查位数i是否为1，若是则result*=x的2i次方
执行用时 :4 ms, 在所有 C++ 提交中击败了63.32%的用户
内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0||x==1)return 1;
        int sign=n>0?1:(-1);
        long index=n;
        index*=sign;
        double result=1;
        while(index!=0){
            if(index&1!=0){
                result*=x;
            }           
            x=x*x;
            index>>=1;
        }
        return sign>0?result:(1/result);
    }
};
```