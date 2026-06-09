```c++
class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        int L = 0;
        for(int i = 0; i < S.length(); i++){
            if( S[i] == '(' ) L++;
            else if( S[i] == ')' ) L--;
            if(L>1 || (L==1&&S[i]==')')) result.push_back(S[i]);
        }
        return result;
    }
};
```