### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    /**
    * 方法直接抄来，此处主要是为了写题解
    *
    * 一句话算法: 
    * 指针从左往右，遇到高度递增的，则保存在栈中，
    * 遇到高度变小时, 指针位置不变，出栈计算, 
    * 把出栈的柱子元素高度与当前指针指向的元素高度比较，
    * 如当前指针指向的元素高度更大（一般来讲出栈的第一个元素肯定高度比它更大，因为发生的高度递减），
    * 则计算从出栈的元素位置与当前指针的位置距离*出栈元素高度，
    * 这就是出栈元素高度的最大面积范围
    *
    * 如当前指针指向的元素高度更小，那么则继续入栈，因为高度更大的已经出栈计算刨去了，所以栈内维护的是一个单调递增栈。
    *
    */
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<Integer>();
        int i = 0;
        int maxArea = 0;
        int[] h = new int[heights.length + 1];
        h = Arrays.copyOf(heights, heights.length + 1);
        while(i < h.length){
            if(stack.isEmpty() || h[stack.peek()] <= h[i]){
                stack.push(i++);
            }else {
                int t = stack.pop();
                maxArea = Math.max(maxArea, h[t] * (stack.isEmpty() ? i : i - stack.peek() - 1));
            }
        }
        return maxArea;
    }
}
```