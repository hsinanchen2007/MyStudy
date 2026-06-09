### 解题思路
建一个小顶堆，和学生id关联，分数都往小顶堆里面放，最后取平均

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        for (auto &each : items) {
            total[each.front() - 1].push(each.back());
            if (total[each.front() - 1].size() > 5) {
                total[each.front() - 1].pop();
            }
        }

        vector<vector<int>> result;
        for (auto &each : total) {
            int sum = 0;
            while (!each.second.empty()) {
                sum += each.second.top();
                each.second.pop();
            }
            result.push_back({each.first + 1, sum / 5});
        }

        return result;
    }
private:
    map<int, priority_queue<int, vector<int>, greater<int>>> total;
};
```