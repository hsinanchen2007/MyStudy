### 题目描述
给出一个区间的集合，请合并所有重叠的区间。

### 示例

**示例 1:**

```
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```
**示例 2:**

```
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

### 思路
思路其实很简单，就是模拟我们手动合并的过程。我们手动合并的话，会先从起点**最小**的区间开始，与**次小**的区间进行比较，如果没有重叠部分，将**最小**的那个区间记录下来，再把**次小**的区间记为**新的最小区间**；如果有重叠部分，就直接合并，合并的时候，左端点取两者较小值，右端点取二者较大值，然后再将合并后成的新区间与下一个区间合并，重复此过程。

### 代码
```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return intervals;
        }
        // 实现Comparator接口进行排序
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                }
                return o1[0] - o2[0];
            }
        });
        int left = intervals[0][0], right = intervals[0][1];
        List<int[]> list = new ArrayList<>();
        for (int i = 1; i < intervals.length; i++) {
            // 由于排过序了，则intervals[i][0] 一定不小于left，所以只需要比较intervals[i][0]和right的大小关系
            if (intervals[i][0] <= right) {
                right = Math.max(right, intervals[i][1]);
            } else {
                // 无重叠部分，先把上一段区间加到list中
                list.add(new int[]{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        list.add(new int[]{left, right});
        int[][] result = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            result[i] = list.get(i);
        }
        return result;
    }
}

```
