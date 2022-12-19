### 解题思路

使用递归与循环，10以外的数最终会被转换成10以内的，10以内的数除了1和7，其他都为false

![image.png](https://pic.leetcode-cn.com/663d50ee391b1572c3db800a621691b5bfb55d671d720ed2dad56999cdbf7eb4-image.png)


### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        if (n == 1 || n == 7) {
            return true;
        } else if (n < 10) {
            return false;
        }
        int res = 0;
        while (n > 0) {
            int bit = n % 10;
            res += bit * bit;
            n = n / 10;
        }
        return isHappy(res);
    }
}
```