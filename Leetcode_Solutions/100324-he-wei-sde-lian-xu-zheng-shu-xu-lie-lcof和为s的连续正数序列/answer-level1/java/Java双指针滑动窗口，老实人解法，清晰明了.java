### 解题思路
sum保存前n个数字的和，区间 2 - 5之间的和，可以由sum[5] - sum[2]得到，初始sum[0] = 0,sum[1] = 1
r,l双指针维护一个滑动窗口
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int[] sum = new int[target + 1];
        for (int i = 1; i <= target; ++i)
            sum[i] = sum[i - 1] + i;
        List<int[]> rs = new ArrayList<>();
        int l = 0, r = 1;
        int half = (target >>> 1) + 1;
        while (l < r && r <= half) {
            int cur = sum[r] - sum[l];
            if (cur == target) {
                if (r - l > 1) {
                    int[] tmp = IntStream.rangeClosed(l + 1, r).toArray();
                    rs.add(tmp);
                }
                // 这里可以移动2格，当 2 + 3 + 4 = 9时, 3 + 4 或 3 + 4 + 5 不可能 = 9
                l += 2;
                r++;
            } else if (cur < target) {
                r++;
            } else {
                l++;
            }
        }
        int sz = rs.size();
        int[][] result = new int[sz][];
        for (int i = 0; i < sz; ++i) 
            result[i] = rs.get(i);
        return result;
    }
}
```