## 思路
先排序，然后从头开始遍历，将每个时间转换为分钟数，比较相邻两个时间差值，最后在比较首尾两个时间差值。
**注意：不要忘记比较首尾时间**
### 代码
```c++
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int min = 1440;
        int size = timePoints.size();
        for (int i = 1; i < size; ++i) {            
            int time1 = time2num(timePoints[i-1]);
            int time2 = time2num(timePoints[i]);            
            if (time2 - time1 < min) {
                min = time2 - time1;
            } 
        }
        //比较首尾时间
        if (time2num(timePoints[0]) + 1440 - time2num(timePoints[size-1]) < min) {
            min = time2num(timePoints[0]) + 1440 - time2num(timePoints[size-1]);
        }
        return min;
    }
    int time2num(const string &str) {
        int num1 = stoi(str.substr(0, 2)) * 60;
        int num2 = stoi(str.substr(3, 2));
        return num1 + num2;
    }
};
```
