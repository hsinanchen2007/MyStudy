 ### 区间合并

给定 n 个区间 [li,ri] ，要求合并所有有交集的区间

思路：

1. 按照区间左端点排序
2. 扫描区间，将有交集区间合并

```
    public int[][] merge(int[][] intervals) {
        if(intervals == null || intervals.length < 2)
			return intervals;
        
        Arrays.sort(intervals, (o1, o2) -> o1[0] - o2[0]);
        
	ArrayList<int[]> res = new ArrayList<>();
	int len = intervals.length;
	for(int i = 0 ; i < len  ; i ++) {
		int[] temp = new int[2];
		temp[0] = intervals[i][0];
		temp[1] = intervals[i][1];
		while(i < len - 1 && temp[1] >= intervals[i + 1][0]) {//寻找本区间的可合并区间，有的话就合并
			temp[1] = Math.max(temp[1],intervals[i + 1][1]);
			i++;//标记到下一个待确认区间
		}
		res.add(temp);
	}
        
        int[][] arr = new int[res.size()][2];
	res.toArray(arr);
	return arr;
    }
```

 



 
