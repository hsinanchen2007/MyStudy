### 解题思路
题目需要记录的信息量有点多，首先是每一列的B的个数需要记录；其次，当每一行的个数满足N，它才有资格进入到判定队列里面，然后利用string将每一行的字符串拼接起来，作为key放入到哈希表里面，记录下该行的个数；

最后遍历一下列，如果列的B满足条件，然后check列中有B的一行是不是存在于map里面，而且数量是不是N，如果都满足，说明该列的B所在行都相等，不多也不少，就可以了。

### 代码

```cpp
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int ans = 0;
        map<int, int> colMap;
        map<string, int> lineMap;
        vector<string> strVec;
        for (int j = 0; j < picture[0].size(); j++) {
            colMap[j] = 0;
            for (int i = 0; i < picture.size(); i++) {
                if (picture[i][j] == 'B') {
                    colMap[j]++;
                }
            }
        }
        for (int i = 0; i < picture.size(); i++) {
            string s;
            int count = 0;
            for (int j = 0; j < picture[i].size(); j++) {
                s.push_back(picture[i][j]);
                if (picture[i][j] == 'B') {
                    count++;
                }
            }
            strVec.push_back(s);
            if (count == N) {
                if (lineMap.find(s) == lineMap.end()) {
                    lineMap[s] = 1;
                } else {
                    lineMap[s]++;
                }
            }
        }
        for (int j = 0; j < picture[0].size(); j++) {
            if (colMap[j] == N) {
                for (int i = 0; i < picture.size(); i++) {
                    if (picture[i][j] == 'B') {
                        if (lineMap.find(strVec[i]) != lineMap.end() && lineMap[strVec[i]] == N) {
                            ans += N;
                        } 
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
```