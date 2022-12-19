### 解题思路


### 代码
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //读取每个攻击时间的间隔 然后判断duration和每个间隔之间的长短
        int total = 0;
        if(timeSeries.size()==0)
            return 0;
        for(int i = 0;i<timeSeries.size() - 1;i++){
            total += min(timeSeries[i+1]-timeSeries[i],duration);
        }
        return duration +total;
    }
};
