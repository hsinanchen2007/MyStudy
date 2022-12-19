其实第一遍想的时候还是晕的
然后第二次换了个思路
果然好久没打游戏了吗

思路如下：
一次遍历
遍历存储一个res作为return value

重点之一是对于题目的理解
如果前后的差不足以结束中毒就加上这段时间
如果足够就只用加上中毒时间
以上
`class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        if(timeSeries.length==0)return 0;
        int res = 0;
        for(int i = 0; i < timeSeries.length-1 ;i++){
            if(timeSeries[i] + duration > timeSeries[i+1]){
                res += timeSeries[i+1] - timeSeries[i];
            }
            else{
                res+=duration;
            }
        }
        return res+duration;
    }
}`