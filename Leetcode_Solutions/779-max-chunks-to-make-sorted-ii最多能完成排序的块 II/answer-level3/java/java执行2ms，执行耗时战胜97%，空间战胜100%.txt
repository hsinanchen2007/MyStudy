从右往左记录累计最小值，从左往右取最大值和累计最小值进行比较
```
class Solution {
    public int maxChunksToSorted(int[] arr) {
         int len = arr.length;
        int[] mins = new int[len];
        for (int i = len - 1; i >= 0; i--) {
            if (i == (len - 1)) {
                mins[i] = arr[i];
                continue;
            }
            mins[i] = Math.min(arr[i], mins[i + 1]);
        }

        int chunks = 0;
        Integer max = null;
        for (int i = 0; i < len; i++) {
            if (max == null) {
                max = arr[i];
            }
            max = Math.max(max, arr[i]);
            if (i + 1 == len) {
                chunks++;
                continue;
            }
            if (max <= mins[i + 1]) {
                chunks++;
                max = null;
            }
        }
        return chunks;
    }
}
```
更多题解请关注[这里](https://github.com/JessenPan/leetcode)，题解持续关注，请关注！