![Jietu20200206-212843.png](https://pic.leetcode-cn.com/c8a83b9e908554daf229de98b002f24d6f98e12b9d8d8d0a2bf0730037d9743a-Jietu20200206-212843.png)


### 代码

```java
class Solution {
    //使用递归的方法
    public double myPow(double x, int n) {
        //边界条件与特殊值的处理
        if(n == 0||x==1.0) return 1.0 ;
        if(x==-1) return n%2==0 ? 1 : -1;
        if (n == -2147483648) return 0;
        //
        if(n < 0) return 1.0 / myPow(x, -n);
        if(n%2 == 1 ) return x * myPow(x,n-1);
        double result = myPow(x,n/2);
        return result * result;
    }


    //使用非递归的方法
    /*public double myPow(double x, int n) {
        
    }*/
}
```