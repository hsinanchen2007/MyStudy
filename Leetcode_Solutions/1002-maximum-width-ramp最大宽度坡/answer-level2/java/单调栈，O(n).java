https://leetcode-cn.com/problems/longest-well-performing-interval/
这道题是本题的加强版，思想是一样的
```
class Solution {
    public int maxWidthRamp(int[] A) {
        Stack<Integer> sk = new Stack<>();
        int n = A.length;
        if (n == 1) return 0;
        sk.push(0);
        for (int i=1; i<n; i++)
            if (A[i] < A[sk.peek()])
                sk.push(i);
        int i = n-1;
        int ans = 0;
        while (i > 0) {
            while (!sk.isEmpty() && A[i] >= A[sk.peek()]) {
                ans = Math.max(ans, i - sk.peek());
                sk.pop();
            }
            i--;
            if (sk.isEmpty()) break;
        }
        return ans;
    }
}
```
