### 解题思路
遍历的时候用int[] lastInterval来存储上一个数组
若lastInterval为空或者lastInterval[1] < interval[0]，则将当前interval添加进list
若当前lastInterval不为空且lastInterval[1] >= interval[0]，同时lastInterval[1] < interval[1]，就修改lastInterval[1]为interval[1]即可，还是挺优雅的。

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length < 2) return intervals;
        // 排序：根据区间开始值升序
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        List<int[]> list = new ArrayList<>();
        int[] lastInterval = null;
        for (int[] interval : intervals) {
            if(lastInterval == null || lastInterval[1] < interval[0]){
                lastInterval = interval;
                list.add(lastInterval);
            }else if(lastInterval[1] < interval[1]){
                lastInterval[1] = interval[1];
            }
        }
        int[][] result = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            result[i][0] = list.get(i)[0];
            result[i][1] = list.get(i)[1];
        }
        return result;
    }
}
```