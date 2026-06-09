```
public class Soluation{
	private List<SortArray> sortArrays;
	private int[][]         intervals;
	private int[][]         arrRes;
    public int[][] merge(int[][] intervals) {
        if (null == intervals || intervals.length <=1) {
			return intervals;
		}
        this.intervals = intervals;
        //排序
        sortArea();
        //合并
        mergeArea();
    	return arrRes;
    }
    private void mergeArea(){
    	//保存合并区域结果
    	SortArray[] arrResList = new SortArray[sortArrays.size()];
    	int         	 start = 0;
    	SortArray        curr  = null;
    	//开始合并
    	for (int i = 0; i < sortArrays.size(); i++) {
    		curr   = sortArrays.get(i);
			if (0 == i) {
				arrResList[start] = new SortArray(curr);
			}else{
				//判断是否可以合并
				if (arrResList[start].canMerge(curr)) {
					arrResList[start].end = Math.max(arrResList[start].end, curr.end);
				}else{
					arrResList[++start] = new SortArray(curr);
				}
			}
		}
    	//输出结果集
    	arrRes = new int[start+1][2];
    	for (int i = 0; i <= start; i++) {
    		 curr   = arrResList[i];
    		 arrRes[i][0] = curr.start;
    		 arrRes[i][1] = curr.end;
		}
    }
    private void sortArea(){
    	//按start进行排序
        sortArrays = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
			sortArrays.add(new SortArray(intervals[i][0], intervals[i][1]));
		}
        //按start排序
        Collections.sort(sortArrays);
    }
}
class SortArray implements Comparable<SortArray>{
	int start;
	int end;
	public SortArray(int start,int end) {
		this.start = start;
		this.end   = end;
	}
	public SortArray(SortArray array){
		this.start = array.start;
		this.end   = array.end;
	}
	@Override
	public int compareTo(SortArray o) {
		return start - o.start;
	}
	/**
	 * 判断是否可以合并
	 * @param array
	 * @return
	 */
	public boolean canMerge(SortArray array){
		return this.end >= array.start;
	}	
```
