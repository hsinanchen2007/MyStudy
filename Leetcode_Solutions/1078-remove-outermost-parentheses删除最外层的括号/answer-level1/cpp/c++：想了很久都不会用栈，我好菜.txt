
```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res, tmp;
        int sum = 0;

        for (int i = 0; i < S.size(); i++){
            tmp += S[i];
            if (S[i] == '(')
                sum++;
            else
                sum--;
            if (sum == 0){
                res.append(tmp.begin() + 1, tmp.end() - 1);
                tmp = "";
            }
        }
        return res;
    }
};
```