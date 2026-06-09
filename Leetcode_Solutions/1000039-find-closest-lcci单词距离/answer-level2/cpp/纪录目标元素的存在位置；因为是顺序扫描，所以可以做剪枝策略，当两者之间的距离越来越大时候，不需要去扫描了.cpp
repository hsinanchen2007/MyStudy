### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> pos;
        int minDis = 1089;
        int tempDis;
        int curDis;
        for (int i = 0; i < words.size(); i++) {
            if ((words[i].compare(word1) == 0) || (words[i].compare(word2) == 0)) {
                pos[words[i]].push_back(i);
                //cout << i << endl;
            }
        }

        for (int i = 0; i < pos[word1].size(); i++) {
            for (int j = 0; j < pos[word2].size(); j++) {
                cout << i << j << endl;
                curDis = abs(pos[word1][i] - pos[word2][j]);
                if (j < pos[word2].size() -1) {
                    tempDis = abs(pos[word1][i] - pos[word2][j + 1]);  // pre read window
                }
                minDis = min(minDis, abs(pos[word1][i] - pos[word2][j]));
                if ((tempDis > curDis) || (minDis == 1)) {
                    break; // 
                }
            }
        }
        return minDis;  
    }
};
```