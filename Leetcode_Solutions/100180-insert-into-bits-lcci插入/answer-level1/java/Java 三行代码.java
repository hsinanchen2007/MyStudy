![插入.png](https://pic.leetcode-cn.com/640200c4f317b024507e788ab1255eb0d590b663436701cc0c44877a7504fcb7-%E6%8F%92%E5%85%A5.png)

### 解题思路
如代码和注释所示，利用`Integer.rotateLeft()`方法。

### 代码

```java
class Solution {
    public int insertBits(int N, int M, int i, int j) {
        for (int distance = i; distance < j + 1; distance++)
            // 将11111111111111111111111111111110首尾循环移动 distance 位并与 N 与运算将第 distance 位清零
            N = N & Integer.rotateLeft(~1, distance);
        return N | (M << i);
    }
}
```