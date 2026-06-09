```
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        
        //数组长度为0或1时
        if(timeSeries.length==0) return 0;
        if(timeSeries.length==1) return duration;

        int time = 0;
        //中毒状态就两种；
        //第一种是前一次中毒后的结束时间超过下一次中毒的开始点,此时t+=a[i]-a[i-1]
        //第二种是前一次中毒时间与下一次中毒时间没有交叉,此时t+=d
        //最后一次要加上一整段中毒时间
        for(int i=1;i<timeSeries.length;i++){
            if(timeSeries[i-1]+duration>timeSeries[i]){
                time += timeSeries[i]-timeSeries[i-1];
            }
            else{
                time += duration;
            }
        }
        return time+duration;
    }
}
```
