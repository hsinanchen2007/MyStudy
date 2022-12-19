### 解题思路
此处撰写解题思路

### 代码

```java
public class Solution {
    public int largestRectangleArea(int[] heights) {
        int max=0;
        Stack<Integer> stack=new Stack<>();
        stack.push(-1);
        
       for(int i=0;i<heights.length;i++)
       {
           while(stack.peek()!=-1&&heights[stack.peek()]>=heights[i])
           max=Math.max(max,heights[stack.pop()]*(i-stack.peek()-1));
        
           stack.push(i);
       }
        while(stack.peek()!=-1)
        max=Math.max(max,heights[stack.pop()]*(heights.length - stack.peek() -1));
       return max;
}
}
```