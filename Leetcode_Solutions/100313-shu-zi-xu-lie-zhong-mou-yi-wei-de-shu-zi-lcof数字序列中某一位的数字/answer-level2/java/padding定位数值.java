### 解题思路
本题采用补零的办法来找到第n个数字所在的数：

    1. n >= 10时，一定是2位以上, 0-9就要补位成00-09，都变成两位的数值表示, 此时n也会发生变化:n = n + 10;
    2. n >= 100 * 2时，一定是3位以上, 00-99就要补位成000-099，都变成三位的数值表示, 此时n也会发生变化:n = n + 100;
    3. .....

上面的操作进行到，结果所在的数值之前的数都被补位成一样长。
这时可以定位数值为 num = pn / dc, 和数值里的第几位，从而得到结果。

![image.png](https://pic.leetcode-cn.com/27f7a111806f9bb40623eb430b3daf21fd54dc4748893f90bc94e38bb8ad6e74-image.png)

### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        long pn = n;
        long cur = 10;
        int dc = 1;
        while (pn >= cur * dc) {
            pn += cur;
            dc++;
            cur *= 10;
        }

        long num = pn / dc;
        long pos = dc - pn % dc;

        int result = 0;
        for (int i = 0; i < pos; i++) {
            result = (int) (num % 10);
            num /= 10;
        }

        return result;
    }
}
```