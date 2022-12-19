### 解题思路
将所有数据绑定成桶，再进行处理

### 代码

```cpp
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        map<char, vector<string>> maps;
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            if (maps.find(words[i].front()) != maps.end()) {
                maps[words[i].front()].push_back(words[i]);
            } else {
                vector<string> vecTmp = {words[i]};
                maps.insert(make_pair(words[i].front(), vecTmp));
            }
        }
        for (int i = 0; i < S.size(); i++) {
            if (maps.find(S[i]) != maps.end()) {
                //开始剔除
                vector<string> vecResult = maps[S[i]];
                vector<string> newVec;
                maps.erase(S[i]);
                for (int j = 0; j < vecResult.size(); j++) {
                    if (vecResult[j].size() == 1 || vecResult[j].size() == 0) {
                       count++;
                        continue;
                    } else {
                        string str = vecResult[j].substr(1, vecResult[j].size() - 1);
                        if (maps.find(str.front()) != maps.end()) {
                            maps[str.front()].push_back(str);
                        } else {
                            vector<string> vecTmp = {str};
                            maps.insert(make_pair(str.front(), vecTmp));
                        }
                    }
                }
            }
        }
        return count;
    }
};
```