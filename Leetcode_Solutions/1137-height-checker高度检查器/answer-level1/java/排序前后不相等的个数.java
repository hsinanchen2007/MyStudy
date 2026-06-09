### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int heightChecker(int[] heights) {
        int[] copy = heights.clone();
        Arrays.sort(copy);
        int res = 0;
        for (int i = 0; i < heights.length; i++) {
            if (heights[i] != copy[i]) {
                res++;
            }
        }
        return res;
    }
}
```