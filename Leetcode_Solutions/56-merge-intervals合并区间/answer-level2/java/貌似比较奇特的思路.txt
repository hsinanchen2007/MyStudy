### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> data = new ArrayList<>();
        // 先排序
        Arrays.sort(intervals, Comparator.comparingInt(o -> o[0]));
        int lastValue = Integer.MIN_VALUE;
        for (int i = 0; i < intervals.length; i++) {
            int[] temp = intervals[i];
            if (temp[0] <= lastValue) {
                continue;
            }
            lastValue = temp[1];
            //  以此向前拓展，直到断裂，开始新的一段
            for (int j = i + 1; j < intervals.length; j++) {
                if (intervals[j][0] <= lastValue) {
                    lastValue = Math.max(lastValue, intervals[j][1]);
                } else {
                    break;
                }
            }
            temp[1]=lastValue;
            data.add(temp);

        }

        return data.toArray(new int[][]{});
    }
}
```