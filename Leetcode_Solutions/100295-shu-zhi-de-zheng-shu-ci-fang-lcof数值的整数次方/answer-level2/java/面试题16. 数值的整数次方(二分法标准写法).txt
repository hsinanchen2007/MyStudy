### 解题思路
主要注意的坑有：
1.底数=0直接返回0
2.底数=1直接返回1
3.指数<0，先取绝对值再对结果求倒数
4.指数=0直接返回1
5.指数=1直接返回底数
4和5的判断放于子函数中，二分法主要采用递归，用位与运算来判断奇偶性加快效率。

### 二分法

```java
class Solution {
    public double myPow(double x, int n) {
        boolean invalidInput=false;
        if(x==0.0&&n<0){
            invalidInput=true;
            return 0.0;
        }
        if(x==1)return 1.0;
        int absN=n;
        if(n<0){
            absN=-n;
        }
        double result=Pow(x,absN);
        if(n<0){
            result=1.0/result;
        }
        return result;
    }
    private double Pow(double x,int n){
        if(n==0)return 1;
        if(n==1)return x;
        double subResult=Pow(x, (int) Math.floor(n/2));
        return (n&1)==1?subResult*subResult*x:subResult*subResult;
    }
}
```