```
import java.util.Arrays;

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a, b)->{
            return a[0]>b[0]?1:a[0]==b[0]?0:-1;
        });//lamda表达式
        int i=0;//原地保存结果
        for(int [] arr:intervals){
            if(i<1 || intervals[i-1][1]<arr[0]){
                intervals[i++]=arr;
            }else{
                intervals[i-1][1]=Math.max(intervals[i-1][1],arr[1]);
            }
        }
        return Arrays.copyOf(intervals,i);
    }
}
```
