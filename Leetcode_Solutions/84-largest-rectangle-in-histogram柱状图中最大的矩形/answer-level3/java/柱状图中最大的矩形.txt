### 解题思路
1. 想不出来。。。看到题解好几种解法，很惭愧。。
2. 和接雨水那个一样，需要找到规律。
3. 这个题的直接做法是遍历所有的柱状图组合，然后找到每一个中最小的柱，乘以长度就是对应的面积，找到最大的就是结果。
4. 然后还可以采用分治的思想，最大的面积，要么是以当前柱状图最小的柱获得的面积，要么是左侧或者右侧最小的柱获得的面积。
5. 还有一种采用栈的方法，如下，这个方法比较巧妙，很难想到，理解理解吧。


### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights == null || heights.length == 0) return 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int maxarea = 0;
        for(int i = 0; i < heights.length; i++){
            while(stack.peek() != -1 && heights[stack.peek()] >= heights[i])
                maxarea = Math.max(maxarea, heights[stack.pop()] * (i - stack.peek() - 1));
            stack.push(i);
        }
        while(stack.peek() != -1 && heights[stack.peek()] > 0)
            maxarea = Math.max(maxarea, heights[stack.pop()] * (heights.length - stack.peek() - 1));
        return maxarea;
    }
}
```