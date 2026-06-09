排完序比较有无重合部分，有的话就合并，加入到list中

class Solution {
    public int[][] merge(int[][] intervals) {
        //由于不清楚最后有几个区块，所以构造一个list暂时存放
        ArrayList<int[]> al = new ArrayList<>();
        //少于两个直接返回
        if(intervals==null||intervals.length<2) return intervals;
        //将intervals按照区间左开口大小排序
        Arrays.sort(intervals,new Comparator<int[]>(){
            public int compare(int[] o1, int[] o2){
                return o1[0]-o2[0];
            }
        });
        //比较有无重合部分
        int i=0,j=0;
        for(;j<intervals.length-1;++j){
            if(intervals[i][1]>=intervals[j+1][0]){
                //当有重合部分时，比较两个区间的右端点，取较大的一个为新的右端点。
                intervals[i][1]=Math.max(intervals[i][1],intervals[j+1][1]);
            }else{
                //无重合部分时，则说明已有一个确定的区间，将其加入到list中。
                al.add(intervals[i]);
                i=j+1;
            }
        }
        al.add(intervals[i]);
        int[][] res = new int[al.size()][];
        //将区间从list中取出。
        for(int k=0;k<al.size();++k){
            res[k]=al.get(k);
        }
        return res;
    }
}