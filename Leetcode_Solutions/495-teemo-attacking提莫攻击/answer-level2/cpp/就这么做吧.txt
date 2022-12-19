思路还是很简单的。

# 原始

看看下波毒会到哪。

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;
        int time = -1;
        for(int i=0;i<timeSeries.size();i++){
            if(time < timeSeries[i]){
                time = timeSeries[i]+duration-1;
                sum += duration;
            }else{
                sum += (timeSeries[i]+duration-1-time);
                time = timeSeries[i]+duration-1;
            }
        }
        return sum;
    }
};
```

改进改进。

## 改进

连续差和duration比较求和。

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len = timeSeries.size();
        if(len == 0){
            return len;
        }
        int sum = 0;
        for(int i=1;i<len;i++){
            sum += min(timeSeries[i]-timeSeries[i-1],duration);
        }
        return sum + duration;
    }
};
```