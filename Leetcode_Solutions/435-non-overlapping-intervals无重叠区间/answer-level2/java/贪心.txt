```
public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals==null||intervals.length<2)
            return 0;
        Arrays.sort(intervals,(int1,int2)->(int1[0]-int2[0]));
        int ans=0;
        for (int i = 0; i <intervals.length ; ) {
            int right=intervals[i][1];
            while (i<intervals.length-1&&right>intervals[i+1][0] ){//重叠？：当前区间的right大于下一区间的left
                i++;
                ans++;
                right = Math.min(right, intervals[i][1]);
                //[[1,100],[11,22],[1,11],[2,12]]    [1,100],[1,11],[2,12],[11,22]
                //因为左边界已经排序，所以当前区间的left一定小于等于下一区间的left，不需要处理
                //应该先剔除掉[1,100]，方法为更新right为当前right和下一个区间right的较小者
            }
            i++;
        }
        return ans;
    }
```
