### 解题思路
通过新区间的左区间与数组中各个区间的右区间来判断插入位置，代码有详细解释

### 代码

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<int[]>();
		if (intervals.length == 0 && newInterval.length == 0) {
			return res.toArray(new int[0][]);
		}
		if (newInterval.length == 0) {
			return intervals;
		}
		if (intervals.length == 0) {
			res.add(newInterval);
			return res.toArray(new int[0][]);
		}
		int i = 0;
		boolean flag = true;//判断区间需不要插入
		while (i < intervals.length) {
			int left = intervals[i][0];
			int right = intervals[i][1];
			if (flag && newInterval[0] <= right) {// 当新区间的左区间小于等于当前遍历的右区间，则找到插入位置
				if (newInterval[1] < left) {// 若当前新区间的右区间小于当前遍历的左区间，则不能合并，直接插入即可；
					res.add(new int[] { newInterval[0], newInterval[1] });
				} else if (newInterval[1] <= right) {// 若新区间的右区间等于当前遍历的左区间或右区间，则和当前区间合并
					left = Math.min(left, newInterval[0]);
				} else {
					left = Math.min(left, newInterval[0]);
					right = newInterval[1];
					while (i + 1 < intervals.length && right >= intervals[i + 1][0]) {// 若新区间的右区间大于当前遍历的右区间，则继续遍历数组并更新right，直到有区间的左区间大于right
						i++;
						right = Math.max(right, intervals[i][1]);
					}
				}
				flag = false;//已经插入新区间，不再需要插入新区间
			}
			res.add(new int[] { left, right });
			i++;
		}
        if (flag) {//要插入数组的最后
			res.add(new int[] { newInterval[0], newInterval[1] });
		}
		return res.toArray(new int[0][]);
    }
}
```