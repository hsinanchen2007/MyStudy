```
class Solution {
    public int videoStitching(int[][] clips, int T) {
        int res = 0;
        int e = 0;
        while (e < T) {
            int tmp = e;
            e = getLongest(e, clips);
            if (tmp == e) return -1;
            ++res;
        }
        return res;
    }

    // 获取最长片段，输入起点，输出终点
    private int getLongest(int s, int[][] clips) {
        int max = 0;
        for (int[] c : clips) {
            if (c[0] <= s && c[1] >= s) max = Math.max(max, c[1]);
        }
        return max;
    }
}
```