### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend==0)
        return 0;
         if (divisor == 1) return dividend;
        if (dividend == -1) return -dividend; 
          if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        int number=0,flag=1;
        if(dividend>0){
            dividend=-dividend;
            flag=-flag;
        }
        if(divisor>0){
            divisor=-divisor;
            flag=-flag;
        }
         while(dividend<=divisor){
            dividend-=divisor;
            number++;
            }
         if(flag==-1)
        return -number;
        else return number;
        } 
}
```