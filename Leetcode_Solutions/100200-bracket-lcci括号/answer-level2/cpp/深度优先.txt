### 解题思路
分别记录字符**(** 与字符**)**的个数，分别为a，b
每次放入（ , 对于字符)的放入，需满足a > b
### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 0) {
            return {};
        }
        string s;
        vector<string> res;
        helper(n, 0, 0, s, res);
        return res;
    }
    void helper(int n, int a, int b, string& s, vector<string>& res) {
        if (a > n || b > n || b > a) {
            return;
        }
        if (a == n && b == n) {
            res.push_back(s);
            return;
        }

        s.push_back('(');
        helper(n, a + 1, b, s, res);
        s.pop_back();
        if (a > b) {
            s.push_back(')');
            helper(n, a, b + 1, s, res);
            s.pop_back();
        }
    }
};
```