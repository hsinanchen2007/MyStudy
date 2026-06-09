设变量flag表示括号深度，当flag归零，就说明到了最外围括号

代码：
```
class Solution {
public:
    string removeOuterParentheses(string S) {
        int flag = 0;
        int len = S.length();
        string ans = ""; 
        for (int i = 0; i < len; i++) {
            if (S[i] == '(') {
                if (flag != 0)
                    ans.push_back(S[i]);
                flag++;
            }
            else if (S[i] == ')') {
                if (flag != 1)
                    ans.push_back(S[i]);
                flag--;
            }
        }
        return ans;
    }
};
```
