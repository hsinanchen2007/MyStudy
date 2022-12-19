根据《组合数学》
有不尽相异元素的全排列公式：
RP(n,n) = n!/(n1!*n2!* ... * nt!)


阶乘即时用long也会溢出，所以这里稍微优化一下。
```java
class Solution {
    public int uniquePaths(int m, int n) {
        if(m<n){
            int temp = m; m=n;n=temp;
        }
        return (int)( multi(m,m+n-2)/multi(1,n-1));
    }
    public long multi(int start,int end){
        long x = 1;
        for(int i=start;i<= end;i++) x*=i;
        return x;
    }
}
```