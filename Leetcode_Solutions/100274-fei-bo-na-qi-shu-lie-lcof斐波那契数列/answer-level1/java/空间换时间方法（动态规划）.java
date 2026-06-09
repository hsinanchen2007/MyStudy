### 解题思路
递归容易溢出，使用空间换时间方法利用数组记录临时变量，使得算法复杂度为o(n)

### 代码

```java
class Solution {
   public int fib(int n) {
       int[] f = new int[n+2];
       f[0]=0;
       f[1]=1;
        for (int i = 2; i <= n; i++) {
          f[i] = ((f[i-1]+f[i-2]) % 1000000007)%1000000007;
        }
        return f[n];
    }
}
```