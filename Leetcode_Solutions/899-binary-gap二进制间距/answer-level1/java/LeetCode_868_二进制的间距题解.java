### 解题思路 & 代码

```java
class Solution {
    public int binaryGap(int N) {
                int last = -1;  // 上一个1的位置
        int maxLen = 0; // 1的最大间隔
        for (int j = 0; j < 32; j++) { // 32表示 2^32次方，循环拿N的2进制位
            if (((N >> j) & 1) == 1) {
                if (last != -1) {
                    maxLen = Math.max(j - last, maxLen);
                }
                last = j;
            }
        }
        return maxLen;
    }
}
```