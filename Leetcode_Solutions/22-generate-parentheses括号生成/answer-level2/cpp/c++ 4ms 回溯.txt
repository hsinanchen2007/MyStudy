### 解题思路
每一步选择'('和')'做判断

### 代码

```cpp
class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string tmp = "";
        generateParenthesis(tmp, 0, n);
        return result;
    }
    void generateParenthesis(string str, int left, int n) {
        if (str.size() == 2*n && left == n) {
            result.emplace_back(str);
            return;
        }
        if (left > n || str.size() > 2*n) return;
        if (left * 2 < str.size()) return;
        generateParenthesis(str + "(", left + 1, n);
        generateParenthesis(str + ")", left, n);
    }
};
```