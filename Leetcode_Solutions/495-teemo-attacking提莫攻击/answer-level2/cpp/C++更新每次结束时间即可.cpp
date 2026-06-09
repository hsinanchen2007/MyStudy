### 解题思路
注意样例的结束时间会爆int，改用long存

### 代码

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        long mark=0,overlap=0;
        for(int i=0;i<timeSeries.size();i++){
            if(timeSeries[i]<mark)overlap+=mark-timeSeries[i];
            mark=timeSeries[i]+duration;
        }
        return timeSeries.size()*duration-overlap;
    }
};
```