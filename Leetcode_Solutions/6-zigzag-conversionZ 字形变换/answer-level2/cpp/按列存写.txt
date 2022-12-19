### 解题思路
执行用时 :
12 ms
, 在所有 C++ 提交中击败了
85.19%
的用户
内存消耗 :
12.2 MB
, 在所有 C++ 提交中击败了
62.12%
的用户

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int num_row = min(numRows, int(s.size()));
        vector<string> new_string(num_row);
        bool tag = false;
        int row = 0;
        for(char c : s){
            new_string[row] += c;
            if(row == 0 || row == num_row-1) tag = !tag;
            row += tag? 1: -1;
        }
        string rt;
        for(string s: new_string){
            rt += s;
        }
        return rt;
    }
};
```