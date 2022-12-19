### 解题思路
此处撰写解题思路
自底向上的递归并且每次算一半应该是最高效的，但是直接2/n，如果除不尽就会损失一个x，因此还需要一个保存取余的结果。
### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        double half = myPow(x,n/2);
        double mod = myPow(x,n%2);
        return half*half*mod;
    }
}
```