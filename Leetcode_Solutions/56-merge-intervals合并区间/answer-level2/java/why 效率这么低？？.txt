```java
class Solution { // 排序即可；
    public int[][] merge(int[][] intervals) {
        int R = intervals.length;
        List<int[]> data = new ArrayList<>();
        for (int i = 0; i < R; ++i) {
            // 现将数组元素保存到
            data.add(new int[] {intervals[i][0], intervals[i][1]});
        }
        Collections.sort(data, (int[] a, int[] b) -> {
            // 根据 start 进行排序；
            return a[0] - b[0];
        });
        // 开始处理元素；
        LinkedList<int[]> temp = new LinkedList<>();
        for (int[] item : data) {
            // int[] last = temp.getLast();
            // 如果为空，或者没有交集；
            if (temp.isEmpty() || temp.getLast()[1] < item[0])  {
                temp.add(item);

            } else {
                temp.getLast()[1] = Math.max(temp.getLast()[1], item[1]);
            }
        }
        int[][] ans = new int[temp.size()][2];
        for (int i = 0; i < temp.size(); ++i) {
            ans[i] = temp.get(i);
        }
        return ans;
    }
}
```
