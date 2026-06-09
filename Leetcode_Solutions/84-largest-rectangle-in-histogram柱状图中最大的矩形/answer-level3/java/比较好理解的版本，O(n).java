利用单调栈分别求出每个数左边大于等于该数的元素个数，以及右边大于等于该数的元素个数，分别保存在dp1和dp2中。然后以每个数作为高度的最大面积=(dp1[i] + dp2[i] + 1) * heights[i]。再遍历一遍求出最大的那个就行了。
```
class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer> sk = new Stack<>();
        int[] dp1 = new int[n];
        int[] dp2 = new int[n];
        for (int i=0; i<n; i++) {
            while (!sk.isEmpty() && heights[sk.peek()] >= heights[i])
                sk.pop();
            if (sk.isEmpty())
                dp1[i] = i;
            else dp1[i] = i - 1 - sk.peek();
            sk.push(i);
        }
        sk.clear();
        for (int i=n-1; i>=0; i--) {
            while (!sk.isEmpty() && heights[sk.peek()] >= heights[i])
                sk.pop();
            if (sk.isEmpty())
                dp2[i] = n - i -1;
            else dp2[i] = sk.peek() - i -1;
            sk.push(i);
        }
        int ans = 0;
        for (int i=0; i<n; i++)
            ans = Math.max(ans, heights[i] * (1 + dp1[i] + dp2[i]));
        return ans;
    }
}
```