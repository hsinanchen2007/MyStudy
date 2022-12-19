性能就不提了，纯粹是简单方便理解，话不多说直接上代码
```
public class Solution {
	private class IntervalComparator implements Comparator<int[]> {
		public int compare(int[] v, int[] w) {
			return v[0]-w[0];
		}
	}
	
	public int[][] insert(int[][] intervals, int[] newInterval){
		
        //构造一个新列表newIntervals，把intervals和newInterval全都塞进去
        ArrayList<int[]> newIntervals = new ArrayList<int[]>();
		newIntervals.add(newInterval);
		for(int[] interval : intervals)
			newIntervals.add(interval);
		
        //将newIntervals中的所有元素排序
		newIntervals.sort(new IntervalComparator());
		
        //构造一个列表merged来合并区间
        LinkedList<int[]> merged = new LinkedList<int[]>();
        
        for(int[] interval : newIntervals){
            
            //如果下一个区间与上一个区间不重叠则直接塞进merged里面
            if (merged.isEmpty() || merged.getLast()[1] < interval[0]) {
                merged.add(interval);
            }
            
            //如果下一个区间与上一个区间重叠就合并
            else {
                merged.getLast()[1] = Math.max(merged.getLast()[1], interval[1]);
            }
        }
        return merged.toArray(new int[0][]);		
	}
}
```
