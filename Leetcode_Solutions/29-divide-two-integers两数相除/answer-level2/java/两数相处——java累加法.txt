### 解题思路
用temp存储被减数，temp_t存储temp为divisor的倍数，
如果temp能作为当前被减数，则temp_t+1直至temp不能作为被减数

### 代码

```java
class Solution {
    public int divide(int dividend, int divisor) {
       int ans = 0, temp = 0,temp_t = 0, flag = dividend^divisor;
        if(dividend==Integer.MIN_VALUE&&divisor==-1){
            return Integer.MAX_VALUE;
        }
        dividend = dividend<0?dividend:-dividend;
        divisor = divisor<0?divisor:-divisor;
        while (dividend<=divisor){
            temp += divisor;
            temp_t++;
            if(temp<0&&dividend-temp<0){
                dividend -= temp;
                ans += temp_t;
            }else {
                dividend -= divisor;
                ans++;
                temp = 0;
                temp_t = 0;
            }
        }
        return flag<0?-ans:ans;
    }
}
```