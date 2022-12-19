### 解题思路
此处撰写解题思路
step1：将pair 对抽象为双向图
step2：深度优先寻找最长的联通区域，记录联通数据以及他们在原始字符串中的位置
step3： 对连通区域和他们在原始字符串中的位置排序，插入原始字符串中
step4： 输出
### 代码

```cpp
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        vector<vector<int>> graph(s.size());
        for (const auto pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        unordered_set<int> seen;

        string tmp;
        vector<int> tmp_idx;
        function<void(int)> dfs = [&](int cur) {
				if (seen.count(cur)) {
                return;
            }
            seen.insert(cur);
            tmp_idx.push_back(cur);
            tmp += s[cur];
            for (int nxt : graph[cur])
                dfs(nxt);
        };
        uint32_t i;
        for (i = 0; i < s.size(); i++) {
            if (seen.count(i)) {
                continue;
            }
            tmp.clear();
            tmp_idx.clear();
            dfs(i);
            sort(begin(tmp), end(tmp));
            sort(begin(tmp_idx), end(tmp_idx));
            int j;
            for (j = 0; j < tmp_idx.size(); j++) {
                s[tmp_idx[j]] = tmp[j];
            }
        }

        return s;
    }
};
```