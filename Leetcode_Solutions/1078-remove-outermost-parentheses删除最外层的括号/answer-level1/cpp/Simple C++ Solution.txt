```
string removeOuterParentheses(string S) {
    string res;
    for (int i = 0, opened = 0; i < S.size(); opened += S[i] == '(' ? 1 : -1, ++i) if (S[i] == '(' && opened > 0 || S[i] == ')' && opened > 1) res.push_back(S[i]);
    return res;
}
```
