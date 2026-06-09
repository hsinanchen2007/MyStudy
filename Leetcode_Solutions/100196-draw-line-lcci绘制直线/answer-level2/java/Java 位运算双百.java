![绘制直线.png](https://pic.leetcode-cn.com/1abf3e25dfb1d618b1a632484d7072ced53a004730fb63930ac66bcdbaeb48a6-%E7%BB%98%E5%88%B6%E7%9B%B4%E7%BA%BF.png)

### 解题思路
详见代码和注释。

### 代码

```java
class Solution {
    public int[] drawLine(int length, int w, int x1, int x2, int y) {
        int[] ret = new int[length];
        // 注意根据所在行数计算偏移量
        int offset = y * w / 32;
        // 首位数字下标
        int head = x1 / 32 + offset;
        // 末位数字下标
        int rear = x2 / 32 + offset;
        // 把涉及到的数全部置 -1 也就是 0b11111111111111111111111111111111
        for (int i = head; i <= rear; i++)
            ret[i] = -1;
        // 调整首位数字
        ret[head] = ret[head] & -1 >>> x1 % 32;
        // 调整末位数字
        ret[rear] = ret[rear] & Integer.MIN_VALUE >> x2 % 32;
        return ret;
    }
}
```