```
public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length <=1) return intervals;
        List<int[]> list = new ArrayList<>();
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0]-o2[0];
            }
        });
        for (int i = 1; i < intervals.length ; i++) {
            if (intervals[i][0] <= intervals[i-1][1]){
                intervals[i][0] = intervals[i][0] < intervals[i-1][0] ? intervals[i][0] : intervals[i-1][0];
                intervals[i][1] = intervals[i][1] < intervals[i-1][1] ? intervals[i-1][1] : intervals[i][1];
            }else{
                list.add(intervals[i-1]);
            }
            if (i == intervals.length - 1){
                    list.add(intervals[i]);
            }
        }
        return list.toArray(new int[0][]);
    }
```
    
    
   
![TIM截图20191217223818.png](https://pic.leetcode-cn.com/6743554661dc578a80d1d59db7d90ff92eaf350ef4f048f013adf2d83a21cca5-TIM%E6%88%AA%E5%9B%BE20191217223818.png)

