```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        int res = 0;
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < heights.length; i ++) {

        int h = heights[i];

            while (!st.isEmpty() && heights[st.peek()] >= h) {
                int top = st.pop();
                res = Math.max(res, heights[top] * (st.isEmpty() ? i : i - 1 - st.peek()));
            }
            st.push(i);
            
        }
        int n = heights.length;
        while (!st.isEmpty()) {
            res = Math.max(res, heights[st.pop()] * (st.isEmpty() ? n : n - st.peek() - 1));
        }
        return res;
    }
}
```