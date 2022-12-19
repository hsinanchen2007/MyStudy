先解决边界条件和溢出情况；然后，转成两正数通过移位进行解答。

```
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag=(dividend ^ divisor)<0;
        int res=0;
        if(divisor==1)
            return dividend;
        if(divisor==INT_MIN){
            return dividend==INT_MIN ? 1 : 0;
        }
            
        if(dividend==INT_MIN){
            if(divisor==-1)
                return INT_MAX;
            else{
                dividend=divisor<0 ? dividend-divisor : INT_MAX-divisor+1;
                res=1;
            }
        }
        dividend=dividend<0 ? 0-dividend : dividend;
        divisor=divisor<0 ? 0-divisor : divisor;
        for(int i=31;i>=0;i--){
            if(dividend>>i >= divisor){
                res+=1<<i;
                dividend-=divisor<<i;
            }
        }
        return flag ? 0-res : res;
    }
};
```
