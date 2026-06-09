### 解题思路
透过现象看本质，就是排序后和排序前有哪些不一样而已。

### 代码

```java
class Solution {
    public int heightChecker(int[] heights) {
        int[] copys = Arrays.copyOf(heights, heights.length);
        Arrays.sort(copys);
        int count = 0;
        for (int i = 0; i < heights.length; i++) {
            if (heights[i] != copys[i]) {
                count++;
            }
        }
        return count;
    }
}
```