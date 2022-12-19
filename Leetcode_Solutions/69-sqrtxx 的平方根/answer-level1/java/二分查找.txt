#### 二分查找
- 注意二分的循环的临界点
- 利用 `m == x/m`的形式来避免大数问题
```java
class Solution {
    public int mySqrt(int x) {
        if(x<0){
            throw new IllegalArgumentException("x's value error");
        }
        if(x==0||x==1){
            return x;
        }
        int i=1,j=x,result=1;
        while(i<=j){
            int m = (i+j)/2;
            if(m==x/m)
                return m;
            if(m>x/m){
                j=m-1;
            }else{
                i=m+1;
                result=m;
            }
        }
        return result;
    }
}
```
#### 牛顿法
利用牛顿迭代公式 
```bash
k^2 = x
=> k^2 -x =0
=> f(k) = k^2 -x

由 f'(k) = 2k  
=> 2k*k约等于f(k)

so: 2k*k = k^2 - x
=> k = k/2 - x/(2k)
 
```
> 注意迭代的临界点，这里因取整，所以临界点取0.5亦可；

```java
    public int mySqrt(int x) {
        if(x<0){
            throw new IllegalArgumentException("x's value error");
        }
        if(x==0||x==1){
            return x;
        }
        double k=1;
        while(Math.abs(x-k*k)>=0.5){
            k = (k+x/k)/2;
        }
        return (int)k;
    }
```