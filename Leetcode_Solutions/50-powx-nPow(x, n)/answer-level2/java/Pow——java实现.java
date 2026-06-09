### 解题思路
首先判断是否有结果为1的条件，
之后判断n是否为负，若为负则转正

用回溯的方法实现Math.pow函数

举例子
假设x=2,n=4,
则会连续进行两次乘x两次，既 2的四次方==2的二次方*2的二次方

若n=6,既把 2的六次方= 2的三次方*2的二次方

若n=8,既把 2的八次方 = 2的二次方*2的二次方*2的二次方

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        double ans = x;
        boolean isNegative = false;
        int count = 0;
        if(n==0||x==1){
            return 1;
        }
        if(n<0){
            n = -n;
            isNegative = true;
        }
        ans = Pow(x,n);
        if(isNegative){
            return 1/ans;
        }else {
            return ans;
        }
    }

    public double Pow(double x, int n){
        if(n==0){
            return 1;
        }else {
            double ans = Pow(x,n/2);
            if(n%2!=0){
                return x*ans*ans;
            }else {
                return ans*ans;
            }
        }
    }
}
```