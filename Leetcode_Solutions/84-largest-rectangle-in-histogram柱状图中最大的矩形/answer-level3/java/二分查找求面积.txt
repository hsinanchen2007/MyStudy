### 解题思路
该代码复制别人的，主要是理解了其中的思想。
通过二分查找进行操作。
首先找到最小值的下标`minIndex`，而后计算最小值的面积，而后再以最小值进行左右划分，即`(start, minIndex - 1)`和`(minIndex + 1, end)`继续进行比较。
至于`sorted = true`是表示该数组时递增数组，直接求最大值即可。

### 代码

```java
class Solution {
    public int calculateArea(int[] heights, int start, int end) {
        if (start > end)
            return 0;
        int minindex = start;
        boolean sorted = true;
        for (int i = start + 1; i <= end; i++){
            if(heights[i - 1] > heights[i])
                sorted = false;
            if (heights[minindex] > heights[i])
                minindex = i;
        }
        
        if(sorted){
            int result = 0;
            for (int i = start; i <= end; i++)
                result = Math.max(result, (end - i + 1) * heights[i]);
            
            return result;
        }

        return Math.max(heights[minindex] * (end - start + 1), Math.max(calculateArea(heights, start, minindex - 1), calculateArea(heights, minindex + 1, end)));
    }
    public int largestRectangleArea(int[] heights) {
        return calculateArea(heights, 0, heights.length - 1);
    }
}
```