
首先我们先对time[i]取模，得到一个每个元素都小于60的time数组，再对每一个出现的元素计算出现次数
然后我们从小到大计算对数，比如对于元素20，我们只需要看看40出现的次数就可以知道元素20对应的匹配对数
对于0和30我们要单独计算，用一下等差数列求和即可


```代码如下 []
class Solution {
public:
     int count[61],res = 0;
     int numPairsDivisibleBy60(vector<int>& time) {
        if(time.empty()) return 0;
        memset(count,0,sizeof count);
        for(int i = 0; i < time.size(); i++){
            time[i] %= 60;
            count[time[i]]++;
        }
        sort(time.begin(),time.end());
        for(int i = 0; i < time.size(); i++){
            if(time[i] >= 30) break;
            if(time[i] == 0) continue;
            res += count[60 - time[i]];
        }
        res += (count[0]*(count[0]-1))/2;
        res += (count[30]*(count[30]-1))/2;
        return res;
     }
};
```
