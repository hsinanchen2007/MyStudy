### 解题思路
此处撰写解题思路
  0 = 0, 1 = 1 , 2= 1 + 0
  利用数组存储计算过的内容   
### 代码

```java
class Solution {
    public int fib(int n) {
        int[] depth = new int[n+1];
        if (n == 0 || n == 1) {
            return n;
        }
        depth[0] =0;
        depth[1] = 1;
        for (int i = 2; i <= n; i++ ) {
            depth[i] = (depth[i-1] +depth[i-2]) % 1000000007 ;
        }
        return depth[n];
    }
}
```