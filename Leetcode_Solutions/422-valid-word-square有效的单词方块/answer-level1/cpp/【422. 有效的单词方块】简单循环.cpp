## 思路
### 代码
```c++
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int size = words.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= size || words[i][j] != words[j][i]) {//注意判断j下标越界
                    return false;
                }
            }
        }
        return true;
    }
};
```
