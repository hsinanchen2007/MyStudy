1. 初始为一个空区间。
2. 每次输入一个数据 val 时，插入一个 [val, val] 区间。
3. 合并相邻的区间。
```
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(const int val) {
        vector<int> newInterval{val, val};
        auto it = intervals.begin();
        while (it != intervals.end()) {
            if (newInterval[1] + 1 < (*it)[0]) {
                intervals.insert(it, newInterval);
                return;
            } else if ((*it)[1] + 1 < newInterval[0]) {
                it++;
                continue;
            } else {
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
                it = intervals.erase(it);
            }
        }
        intervals.push_back(newInterval);
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
    
private:
    vector<vector<int>> intervals;
};
```
