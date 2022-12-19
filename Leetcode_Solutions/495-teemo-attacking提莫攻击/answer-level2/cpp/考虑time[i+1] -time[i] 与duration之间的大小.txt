### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0) return 0;
        int sum = 0;
        for(int i=0;i<timeSeries.size()-1;i++){
            sum+= min(duration, timeSeries[i+1]-timeSeries[i]);
        }
        return sum+duration;
    }
};
```