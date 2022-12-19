### 解题思路
正常遍历，分情况讨论即可。
（感觉这个题应该放在简单难度）

### 代码

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum=0;
        if(timeSeries.empty()) return sum;
        if(timeSeries.size()==1) return duration;

        for(int i=1;i<timeSeries.size();i++)
        {
            if(timeSeries[i]-timeSeries[i-1]>=duration) sum+=duration;
            else sum+=timeSeries[i]-timeSeries[i-1];
        }
        sum+=duration;

        return sum;
    }
};
```