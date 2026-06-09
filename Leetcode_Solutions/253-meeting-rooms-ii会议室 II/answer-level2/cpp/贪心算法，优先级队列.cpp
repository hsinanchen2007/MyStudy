### 解题思路
[[13,15],[1,13]]这个用例预期结果是1，允许end == start

### 代码

```cpp
struct cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a.front() < b.front()) {
            return true;
        } else if (a.front() == b.front() && a.back() - a.front() < b.back() - b.front()) {
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        
        int result = 0;
        priority_queue<int, vector<int>, greater<int>> room;
        
        for (auto each : intervals) {
            if (!room.empty() && each.front() >= room.top()) {
                room.pop();
                room.push(each.back());
            } else {
                room.push(each.back());
                result += 1;
            }
        }
        
        return result;
    }
};
```