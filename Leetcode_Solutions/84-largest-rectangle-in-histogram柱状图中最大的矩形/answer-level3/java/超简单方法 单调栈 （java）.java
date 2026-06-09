### 解题思路
此处撰写解题思路
思路：维护一个单调递增栈 ，如果新进来的比栈顶元素高小的话 栈中大的出栈，更新最大面积值，最后与0比较，目的是将栈内残留元素 全部pop出去。
![image.png](https://pic.leetcode-cn.com/6f62d5625c61f8ce4701881c18b4afeba8957c9ed6a242d7af74eb5588987eb3-image.png)

### 代码

```java
class Solution {

   public static int largestRectangleArea(int[] heights) {
       int areaSize=0;
       if(heights.length==0){
            return 0;
        }
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < heights.length + 1; i++) {
            int high = i < heights.length ? heights[i] : 0;
            while (!stack.isEmpty() && heights[stack.peek()] > high) {
                int index = stack.pop();
                if (!stack.isEmpty()) {
                    areaSize = Math.max(areaSize, heights[index] * (i - stack.peek() - 1));
                } else {
                    areaSize = Math.max(areaSize, heights[index] * i);
                }
            }
            stack.push(i);
        }
        return areaSize;
    }
}
```