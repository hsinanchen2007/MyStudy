```
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int res = 0;
        for (int i = 0; i <= heights.length; i++) 
            if (stack.isEmpty() || (i == heights.length ? 0 : heights[i]) >= heights[stack.peek()])
                stack.push(i);
            else
                res = Math.max(res, heights[stack.pop()] * (stack.isEmpty() ? i-- : --i - stack.peek()));
        return res;
    }
```
<br>

执行顺序和官方题解中的没有差别，可参考官方题解中的图。

```
// hights 6 7 5      2    4 5 9 3
// i      0 1 1 1  2 2  3 4 5 6 6 6  6  7 7  7  8 9
// s.peek 0 1 0 -1 2 -1 3 4 5 6 5 4  3  7 3  -1 8
// area   0 0 7 12 0 15 0 0 0 0 9 10 12 0 12 16 0
```
