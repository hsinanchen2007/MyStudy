### 解题思路
1. 从 1 开始递增
2. 判断是否存在两个数都是无零整数，是则直接返回

![image.png](https://pic.leetcode-cn.com/4d4092ede003ed44e6fd5abf800ce4d5d36dc1c0db797be730990592619e0d99-image.png)
### 代码

```java
class Solution {
   public int[] getNoZeroIntegers(int n) {
        int[] rs = new int[2];
        for (int i = 1; i < n; i++) {
            if (isNoZero(i) && isNoZero(n - i)) {
                return new int[]{i, n - i};
            }
        }
        return rs;
    }

    private boolean isNoZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
}
```