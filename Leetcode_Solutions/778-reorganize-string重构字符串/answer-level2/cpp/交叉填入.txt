### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reorganizeString(string S) {
        if (S.empty()) {
            return "";
        }
        map<char, int> maps;
        for (int i = 0; i < S.size(); i++) {
            if (maps.find(S[i]) != maps.end()) {
                maps[S[i]] = maps[S[i]] + 1;
            } else {
                maps.insert(make_pair(S[i], 1));
            }
        }
        vector<pair<char, int>> vec(maps.begin(), maps.end());
        sort (vec.begin(), vec.end(), [](const pair<char, int> pair1, const pair<char, int> pair2) {
            return pair1.second > pair2.second;
        });
        if (vec[0].second > (S.size() + 1) / 2) {
            return "";
        }
        vector<char> vecResult(S.size(), '0');
        int j = 0;
        for (int i = 0; i < vecResult.size(); i = i + 2) {
            if (vec[j].second == 1) {
                vecResult[i] = vec[j].first;
                vec[j].second = 0;
                j++;
                continue;
            }
            if (vec[j].second > 0) {
                vecResult[i] = vec[j].first;
                vec[j].second--;
            }
        }
        for (int i = 1; i < vecResult.size(); i = i + 2) {
            if (vec[j].second == 1) {
                vecResult[i] = vec[j].first;
                vec[j].second = 0;
                j++;
                continue;
            }
            if (vec[j].second > 0) {
                vecResult[i] = vec[j].first;
                vec[j].second--;
            }
        }
        string s = "";
        for (char ch : vecResult) {
            s = s + ch;
        }
        return s;
    }
};
```