### 解题思路
使用递归方法试了试，效果还可以

### 代码

```java
class Solution {
    boolean invalidInput=false;
    public double myPow(double x, int n) {
        if(n==0) return 1.0;
        if((x==0)&&(n<0)) {
            invalidInput=true;
            return 0.0;
        }
        if((x==0)&&(n>0)) return 0.0;
        if((x!=0)&&(n<0)) return (double)(1.0/postivePow( x, -n ));
         return postivePow(x, n);

    }
    public double postivePow(double x,int n){
        if(n==0||n==1) return x;
        if(n%2==1) return (double)(x*postivePow(x,n-1));
        else return postivePow(x*x,n/2);
    }
}
```