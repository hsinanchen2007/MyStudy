### 解题思路
首先数据规模是$10^5$，所以算法的复杂度最高不能超过$O(n^2)$。连续求和类型，可以联想到使用前缀和先预处理，之后就是查找符合条件的前缀数组的下界和上界。外层循环从0开始遍历下界down，内层循环可以从down+1开始遍历查找up，但是这样开销过大，观察到当down固定的时候每一次up的后移，区间的值是递增的，所以在查找up的时候可以使用二分优化，那么复杂度就可以降到$O(nlogn)$，在可以接受的范围内。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> ans = new ArrayList<>();
        int[] pre = new int[target + 1];
        for (int i = 1; i <= target; ++i) {
            pre[i] = pre[i - 1] + i;
        }
        for (int a = 0; a < (target >> 1); ++a) {
            int b = binSearch(a + 1, target, a, target, pre);
            if (b > a) {
                int[] tmp = new int[b - a];
                int cnt = 0;
                for (int i = a + 1; i <= b; ++i) {
                    tmp[cnt++] = i;
                }
                ans.add(tmp);
            }
        }
        return ans.toArray(new int[0][]);
    }

    // 二分查找上界
    private int binSearch(int l, int r, int a, int target, int[] pre) {
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pre[mid] - pre[a] == target) {
                return mid;
            } else if (pre[mid] - pre[a] > target) {
                r = mid - 1;
            } else l = mid + 1;
        }
        return -1;
    }
}
```