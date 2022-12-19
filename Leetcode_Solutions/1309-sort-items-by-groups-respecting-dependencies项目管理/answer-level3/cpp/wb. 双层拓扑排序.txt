### 解题思路

### 代码

```cpp
class Solution {
public:
    bool Help(unordered_map<int, vector<int>>& mNxt, unordered_map<int, int>& inDegree, set<int>& nodes, vector<int>& ans) {
        queue<int> q;
        for (auto i : nodes) {
            if (inDegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (q.empty() == false) {
            int curr = q.front();
            q.pop();
            for (auto nxt : mNxt[curr]) {
                inDegree[nxt]--;
                if (inDegree[nxt] == 0) {
                    q.push(nxt);
                    ans.push_back(nxt);
                }
            }
        }
        if (ans.size() < nodes.size()) {
            return false;
        }
        return true;
    };
public:
// 0, 634, 1, 52, 7
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, set<int>> mItems;  // <group, items>
        set<int> nodes;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = -1 - k;
                k++;
            }
            mItems[group[i]].insert(i);
            nodes.insert(group[i]);
        }
        unordered_map<int, vector<int>> mNxtGroup;
        unordered_map<int, vector<int>> mNxtItems;
        unordered_map<int, int> inGroup;
        unordered_map<int, int> inItem;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < beforeItems[i].size(); j++) {
                if (group[beforeItems[i][j]] == group[i]) {
                    inItem[i]++;
                    mNxtItems[beforeItems[i][j]].push_back(i);
                } else {
                    inGroup[group[i]]++;
                    mNxtGroup[group[beforeItems[i][j]]].push_back(group[i]);
                }
            }
        }
        bool ret;
        vector<int> groupIdx;
        ret = Help(mNxtGroup, inGroup, nodes, groupIdx);
        if (ret == false) {
            return vector<int>();
        }
        vector<int> itemIdx;
        for (auto g : groupIdx) {
            vector<int> tmp;
            ret = Help(mNxtItems, inItem, mItems[g], tmp);
            if (ret == false) {
                return vector<int>();
            } else {
                itemIdx.insert(itemIdx.end(), tmp.begin(), tmp.end());
            }
        }
        return itemIdx;
    }
};
```