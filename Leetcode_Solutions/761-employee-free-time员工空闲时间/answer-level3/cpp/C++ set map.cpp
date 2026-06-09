### 解题思路
借鉴[1353. 最多可以参加的会议数目]的思路
遍历所有时间点，每位员工开始工作时间点+1，结束工作时间点-1，sum为0的时候就是公共休息时间段的开始。
![图片.png](https://pic.leetcode-cn.com/09fdf59fb090b530358d8d0b7aed0dd4f0a2e5654c297447979f5aa16c1273e8-%E5%9B%BE%E7%89%87.png)

### 代码
```
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        set<int> timepoints;  // 保存所有区间的两端时间点，避免暴力遍历
        int n = schedule.size();
        unordered_map<int, int> Gain[n];  // key: 时间点,  value: +1工作时间开始/-1工作时间结束
        for (int i = 0; i < n; ++i) {
            for (Interval interv : schedule[i]) {
                timepoints.insert(interv.start);
                timepoints.insert(interv.end);
                Gain[i][interv.start] = 1;
                Gain[i][interv.end] = -1;
            }
        }
        int sum = 0;
        int start = -1;
        int end = -1;
        vector<Interval> ans;
        for (int i : timepoints) {
            for (int j = 0; j < n; ++j) {
                if (Gain[j].find(i) != Gain[j].end()) {
                    sum += Gain[j][i];
                }
            }
            if (sum == 0) {  // 所有工作时间区间都已结束，休息开始
                start = i;
            } else {
                if (start != -1) {  // sum从0到非0，有人开始工作了，休息结束
                    end = i;
                    ans.emplace_back(start, end);
                    start = -1;
                }
            }
        }
        return ans;
    }
};
```