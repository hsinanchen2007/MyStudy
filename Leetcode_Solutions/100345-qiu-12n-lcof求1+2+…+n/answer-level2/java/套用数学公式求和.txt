### 解题思路
直接根据求和公式:1+2+3+...+n = n * (n+1)/2，即(n * n + n)/2.
由于不能使用乘除，所以
n * n = (int)Math.pow(n, 2);//使用库函数求出n平方
/2 = >>1;//右移一位表示除2

### 代码

```java

class Solution {
    public int sumNums(int n) {
        return ((int)Math.pow(n, 2) + n) >> 1;
    }
}
```