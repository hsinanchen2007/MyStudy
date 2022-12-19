### 解题思路
先利用哈希表统计每种字串的个数，然后放入堆中，堆要重写仿函数。
特别默认函数是less，如果返回true表示a的优先级低于b(排在后面)，返回false表明a排在b前面

### 代码

```cpp
struct cmp {
    bool operator() (pair<string, int>& a, pair<string, int>& b) {
        if (a.second < b.second) {
            return true;
        } else if (a.second > b.second) {
            return false;
        } else {
            if (a.first >= b.first) {
                return true;
            } else {
                return false;
            }
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::ios::sync_with_stdio(false);
        map<string, int> words2CntMap;
        for (auto& w : words) {
            words2CntMap[w]++;
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> q;
        for (auto& m : words2CntMap) {
            q.push(m);
        }

        vector<string> ans;
        while (!q.empty() && k > 0) {
            pair<string, int> tmp = q.top();
            ans.push_back(tmp.first);
            q.pop();
            k--;
        }

        return move(ans);
    }
};
```