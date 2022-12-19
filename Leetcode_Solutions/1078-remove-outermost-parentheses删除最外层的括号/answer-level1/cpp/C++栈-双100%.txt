### 解题思路

这里将括号进行标注，例如"(()())"对应的数字标号j为"121210"。发现需要删除的括号所对应的条件为
1. 左括号&&j==1;
2. 右括号&&j==0。
根据这两个条件进行删除。
另外，为了避免访问字符串，当不是最外层括号时，直接将左右括号存入答案中。

执行结果为：
![removeOuterParentheses.png](https://pic.leetcode-cn.com/7c158611353684f175d7fe6d59477020b419db11729cd29be06e99e7002bdc89-removeOuterParentheses.png)

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int j = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                j += 1;
                if (j == 1)
                    continue;
                else {
                    ans.push_back('(');
                }
            }
            else {
                j -= 1;
                if (j == 0)
                    continue;
                else {
                    ans.push_back(')');
                }
            }
        }
        return ans;
    }
};
```