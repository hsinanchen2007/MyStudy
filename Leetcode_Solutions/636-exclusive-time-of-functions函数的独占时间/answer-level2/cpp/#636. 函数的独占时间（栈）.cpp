***Talk is cheap. Show me the code.***
``` cpp
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<pair<int, int>> stk;
        for (string &log : logs) {
            size_t pos1 = log.find(':');
            size_t pos2 = log.rfind(':');
            int currId = stoi(log.substr(0, pos1));
            string currAction = log.substr(pos1+1, pos2-pos1-1);
            int currTimestamp = stoi(log.substr(pos2+1));
            if (currAction == "start") {
                stk.push(make_pair(currId, currTimestamp));
            } else {
                int duration = currTimestamp - stk.top().second + 1;
                result[currId] += duration;
                stk.pop();
                if (!stk.empty()) {
                    result[stk.top().first] -= duration;
                }
            }
        }
        return result;
    }
};
```
![1112.png](https://pic.leetcode-cn.com/dc2269d7a70ec17397d80715f3266df779361a6741a45ff4fe6ccb095a40afbf-1112.png)

发现：从字符串log 中提取 id，action，time，尝试过 istringstream::getline 和 string::substr 两种方式，后者速度更快。