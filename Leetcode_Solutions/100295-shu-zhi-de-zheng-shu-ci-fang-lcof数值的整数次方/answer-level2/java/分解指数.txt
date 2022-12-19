### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        double num = Math.pow(x, n/2);
        if(n%2==0)
        return num * num;
        else return num*num*Math.pow(x,n%2);
    }
}
```