在注释里~
```
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        //思路类似485，最大连续1的个数，但是不要求连续，所以不用设置max，和置零
        if(timeSeries == null || timeSeries.length == 0) return 0;
        int cnt = duration;
        //遍历数组，根据连续两个数差值和duration的大小，进行分类，按照分类更新cnt
        for(int i = 1; i < timeSeries.length; i++){
            if(timeSeries[i] - timeSeries[i - 1] >= duration){
                cnt += duration;
            }
            else{
                cnt+=timeSeries[i] - timeSeries[i - 1];
            }
        }
        return cnt;
    }
}
```
