### 解题思路
明显动态规划问题，解题思路类似楼上，一般只要动态规划的 dp 数组是一维的，都可以像下面这样优化为用几个变量来记录之前的状态，不需要一个长度为 n 的 dp 数组

### 代码

```java
class Solution {
    public int translateNum(int num) {
        if (num < 10) {
            return 1;
        }

        int pre = 1, curr = 1;
        String numStr = String.valueOf(num);
        int len = numStr.length();
        int result = 0;
        for (int i = 1; i < len; i++) {
            char c = numStr.charAt(i);
            if (numStr.charAt(i - 1) == '0'
                    || (numStr.charAt(i - 1) == '2' && c >= '6')
                    || numStr.charAt(i - 1) >= '3') {
                result = curr;
            } else {
                result = curr + pre;
            }
            pre = curr;
            curr = result;
        }

        return result;
    }
}
```