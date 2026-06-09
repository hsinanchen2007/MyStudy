小技巧：最外面的左括号跳过，L初始为1；当右括号数量等于左括号数量的位置就是最外面的右括号

执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户

```c++ []
class Solution {
public:
    string removeOuterParentheses(string S) {
        int L=1;int R=0;
        string ans;
        for(int i=1;i<S.size();i++){
            if(S[i]=='(')L++;
            else R++;
            if(R!=L)ans.push_back(S[i]);
            else {
                i++;L=1;R=0;
            }
        }
        return ans;
    }
};
```