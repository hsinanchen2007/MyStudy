### 解题思路
简单的递归思想：
n为正数：
如果n为偶数，则x^n = (x^(n/2))^2;
如果n为奇数，则x^(n-1)为上面那种情况
如果n为负数：
将n设置为正数，最后再除1即可
### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        boolean flag = n<0?true:false;
        if(n==0)
            return 1.0;
        if(n!=Integer.MIN_VALUE)
            n = Math.abs(n);  //abs不能转换MIN_VALUE
        else 
            n = Integer.MAX_VALUE - 1; //MIN_VALUE绝对值为偶数，这里保持一致
        double result;
        if(n%2==0){
            double temp = myPow(x,n/2);
            result = temp*temp;
        }else{
            double temp = myPow(x,(n-1)/2);
            result = x*temp*temp;
        }

        if(flag)
            return 1.0/result;
        else   
            return result;
    }
}
```