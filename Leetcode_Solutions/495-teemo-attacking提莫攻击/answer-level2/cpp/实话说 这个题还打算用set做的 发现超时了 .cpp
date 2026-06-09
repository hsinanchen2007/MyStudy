




`class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //读取每个攻击时间的间隔 然后判断duration和每个间隔之间的长短
        int total = 0;
        if(timeSeries.size()==0) //测试案例 [] 10000 这里需要注意一下
            return 0;
        for(int i = 0;i<timeSeries.size() - 1;i++){
            total += min(timeSeries[i+1]-timeSeries[i],duration);
        }
        return duration +total;//最后一次攻击是一定能上满时间的
    }
};`

