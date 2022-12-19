### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/8faf673994d03adf0fec4eeb1ef86f2c488fab056e57de30a5dddceccfc54479-image.png)

双指针可以是夹逼策略，可以是外扩，也可以是前后和快慢。
刚开始用sort的时候定义了一个static bool, 算到最大总是说overflow,不知道为什么。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        if (intervals.size() == 1) {
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int posScan = 1;
        int posSave =  0;
        //use two pointer
        while(posScan < intervals.size()) {
            if ( intervals[posScan][0] <= intervals[posSave][1]) {
                intervals[posScan][0] = intervals[posSave][0];
                intervals[posScan][1] = max(intervals[posSave][1],intervals[posScan][1]);
                posSave = posScan;
                posScan++;
            }else{
                res.emplace_back(intervals[posSave]);
                posSave = posScan;
                posScan ++;
            }
        }
        res.emplace_back(intervals[posSave]);
        return res;
    }
};
```