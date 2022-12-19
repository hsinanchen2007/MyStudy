### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> maps;
        for (int i = 0; i < S.size(); i++) {
            maps.insert(make_pair(S[i], i));
        }
        vector<pair<char, int>> vector1;
        for (int i = 0; i < T.size(); i++) {
            if (maps.find(T[i]) != maps.end()) {
                vector1.push_back(make_pair(T[i], maps[T[i]]));
            } else {
                vector1.push_back(make_pair(T[i],INT_MAX));
            }
        }
        sort(vector1.begin(), vector1.end(), [](const pair<char, int> pair1, const pair<char, int> pair2) {
           return pair1.second < pair2.second;
        });
        string str = "";
        for (pair<char, int> pair3 : vector1) {
            str = str + pair3.first;
        }
        return str;
    }
};
```