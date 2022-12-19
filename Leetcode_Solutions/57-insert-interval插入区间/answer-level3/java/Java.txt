### 执行用时 :3 ms, 在所有 Java 提交中击败了87.91%的用户
### 内存消耗 :43.3 MB, 在所有 Java 提交中击败了54.29%的用户
```
    public int[][] insert(int[][] intervals, int[] newInterval){
    	List<int[]> res = new LinkedList<int[]>();
    	int i = 0;
    	int n = intervals.length;
    	int nStart = newInterval[0];
    	int nEnd = newInterval[1];
    	//当前区间的end 小于 插入区间的 start，跳过并加入结果集
    	while(i < n && intervals[i][1] < newInterval[0]) {
    		res.add(intervals[i]);
    		i++;
    	}
    	//如果到最后都没找到，把newInterval加到最后
    	if(i == n) {
    		res.add(newInterval);
    		return res.toArray(new int[0][]);
    	}
    	//选择小的 作为新区的 start
    	nStart = Math.min(intervals[i][0],newInterval[0]);
    	//如果当前的start < end 把当前end 和  newInterval的end 比较
    	while(i < n && intervals[i][0] <= newInterval[1]) {
    		nEnd = Math.max(newInterval[1], intervals[i][1]);
    		i++;
    	}
    	res.add(new int[]{nStart,nEnd});
    	
    	//如果后面有没遍历到的 加入最后的结果
    	while(i < n) {
    		res.add(intervals[i++]);
    	}
    	for(int[] x : res) {
    		System.out.println(x[0]+"------"+x[1]);
    	}
    	return res.toArray(new int[0][]);
    }
```
