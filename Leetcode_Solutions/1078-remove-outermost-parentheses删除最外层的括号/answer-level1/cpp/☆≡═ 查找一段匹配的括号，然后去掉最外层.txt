```
class Solution {
public:
    string removeOuterParentheses(const string& S) {
        ostringstream os;
        for (int i = 0; i < S.size(); ) {
            int j = i + 1;
            int cnt = 1;
            for (; j < S.size() && cnt; j++)
                S[j] == '(' ? cnt++ : cnt--;
            os << S.substr(i + 1, j - i - 2);
            i = j;
        }
        return os.str();
    }
};
```
