### 解题思路
感觉和offer上的不一样。。 头铁直接干了

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int len = 1;
        while (n-- > 0) {
            len *= 10;
        }

        int[] ans = new int[len - 1];
        for (int i = 0; i < len - 1; i++) {
            ans[i] = i + 1;
        }

        return ans;
    }
}
```