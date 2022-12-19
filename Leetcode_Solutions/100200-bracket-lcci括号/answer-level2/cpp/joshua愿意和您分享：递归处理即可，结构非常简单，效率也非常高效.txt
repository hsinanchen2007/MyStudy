### 解题思路
joshua愿意和您分享 遵守一条规则即可：如果左括号没有达到上限 n，就继续添加左括号。递归产生就行

### 代码

```cpp
class Solution {
private:
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        product("", n, 0, 0);
        return ans;
    }
    // params:
    // s: 当前已经产生的字符串
    // n: 总共的括号对数
    // l: 已经产生的左括号的次数
    // r: 已经产生的右括号的次数
    void product(string s, int n, int l, int r) {
        // 如果总次数达到 2*n，就表示产生了一个合法的字符串
        if(l+r == 2*n) {
            ans.push_back(s);
            return;
        }
        // 如果左括号没有达到上限 n，就继续添加左括号
        if(l < n) product(s+'(', n, l+1, r);
        // 如果右括号没有超过左括号的数量，就可以考虑继续添加右括号
        if(r < l) product(s+')', n, l, r+1);
    }
};
```