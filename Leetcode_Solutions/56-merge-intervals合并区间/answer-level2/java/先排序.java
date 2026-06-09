### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return intervals;
        }

        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        
        List<int[]> results = new ArrayList<>();

        int[] last = intervals[0];
        for (int i = 1; i < intervals.length; i++) {
            int[] cur = intervals[i];
            if(cur[0] <= last[1]) {
                last[1] = Math.max(last[1], cur[1]);
            } else {
                results.add(last);
                last = cur;
            }
        }

        results.add(last);
        
        int[][] res = new int[results.size()][2];
        for (int i = 0; i < results.size(); i++) {
            res[i] = results.get(i);
        }
        return res;
    }
}

```