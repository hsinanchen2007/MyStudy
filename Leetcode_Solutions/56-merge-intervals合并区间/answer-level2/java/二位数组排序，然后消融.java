### 解题思路


### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] ints1, int[] ints2) {
                if (ints1[0] == ints2[0]) {
                    return ints1[1] - ints2[1];
                }
                return ints1[0] - ints2[0];
            }
        });

        if (intervals.length == 0) {
            return new int[][]{};
        }
        List<int[]> results = new ArrayList<>();
        results.add(new int[]{intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.length; i++) {
            int firstBegin = results.get(results.size() - 1)[0];
            int firstEnd = results.get(results.size() - 1)[1];
            int secondBegin = intervals[i][0];
            int secondEnd = intervals[i][1];
            if (firstEnd >= secondBegin) {
                results.remove(results.size()-1);
                results.add(new int[]{firstBegin, Math.max(firstEnd, secondEnd)});
            } else {
                results.add(new int[]{secondBegin, secondEnd});
            }
        }
        return results.toArray(new int[results.size()][2]);
    }
}
```