### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int[] results = new int[(int)Math.pow(10, n) - 1];
        for (int i = 0; i < results.length; i++) {
            results[i] = i + 1;
        }
        return results;
    }
}
```