### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int[] ret = new int[(int)Math.pow(10, n) - 1];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = i + 1;
        }
        return ret;
    }
}
```