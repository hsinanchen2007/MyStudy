## 思路一：循环打印
### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> vec(numRows);
        int size = s.size();        
        int i = 0;
        while (i < size) {
            for (int j = 0; j < numRows; ++j) {
                if (i < size) {
                    vec[j].push_back(s[i++]);
                } else {
                    break;
                }
            }
            for (int j = numRows - 2; j > 0; --j) {
                if (i < size) {
                    vec[j].push_back(s[i++]);
                } else {
                    break;
                }
            }
        }
        string res;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                res += vec[i][j];
            }
        }
        return res;
    }
};
```
### 优化
时间复杂度：O(n)
```c++
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> vec(numRows);
        bool down = false;        
        int cur = 0;
        for (char c : s) {
            vec[cur] += c;
            if (cur == 0 || cur == numRows - 1) down = !down;
            cur += down ? 1 : -1;
        }         
        string res;
        for (string row : vec) {
            res += row;
        }
        return res;
    }
};
```

