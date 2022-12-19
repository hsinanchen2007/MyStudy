 考虑到只要是3的幂次，个位数字为1 or 3 or 7 or 9, 先判断如果个位数字不是1，3，7，9中的一个，则不是3的幂次。



```
class Solution {
public:
    bool isPowerOfThree(int n) {
        
        int r=n%10;
       
        if(r!=3 && r!=9 && r!=7 && r!=1)
            return false;
        if(n==1)
            return true;
        while(n>1)
        {
            if(n%3!=0)
                return false;
            n=n/3;
        }
        return true;
        
    }
};
```