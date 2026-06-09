```
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int depth = 0;
        int cnt = 0;
        for (char c: seq.toCharArray()) {
            if (c == '(') {
                cnt++;
            } else {
                cnt--;
            }
            depth = Math.max(depth, cnt);
        }
        int halfDepth = depth / 2;
        int[] ans = new int[n];
        cnt = 0;
        for (int i=0; i<n; i++) {
            char c = seq.charAt(i);
            if (c == '(') {
                cnt++;
                if (cnt > halfDepth) ans[i] = 1;
            } else {
                if (cnt > halfDepth) ans[i] = 1;
                cnt--;
            }
        }
        return ans;
    }
}
```