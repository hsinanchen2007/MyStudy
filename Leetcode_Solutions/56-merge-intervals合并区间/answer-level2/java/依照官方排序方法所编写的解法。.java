class Solution {
    public int[][] merge(int[][] intervals) {
        
        if(intervals.length==0)
        {
            return intervals;
        }
        
        for(int i=1;i<intervals.length;i++)
        {
            for(int j=0;j<intervals.length-i;j++)
            {
                if(intervals[j][0]>intervals[j+1][0])
                {
                    int[] temp = intervals[j];
                    intervals[j]=intervals[j+1];
                    intervals[j+1]=temp;
                }
            }
        }//对二维数组使用冒泡排序针对start进行排序
        
        List<int[]> temp = new ArrayList<>();
        
        for(int i=0;i<intervals.length-1;i++)
        {
            if(intervals[i][1]>=intervals[i+1][0])
            {
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=Math.max(intervals[i][1],intervals[i+1][1]);
            }
            else
            {
                temp.add(intervals[i]);
            }
        }
        temp.add(intervals[intervals.length-1]);
        
        int[][] result = new int[temp.size()][2];
        
        for(int i=0;i<temp.size();i++)
        {
            result[i]=temp.get(i);
        }
        return result;//返回二维数组
    }
}