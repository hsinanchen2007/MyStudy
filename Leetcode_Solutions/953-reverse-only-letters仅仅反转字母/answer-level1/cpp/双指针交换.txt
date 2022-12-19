```
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = S.size()-1;
        char c;
        while(i<j)
        {
            if(!isalpha(S[i]))
            {
                i++;
                continue;
            }
            if(!isalpha(S[j]))
            {
                j--;
                continue;
            }
            c = S[i];
            S[i++] = S[j];
            S[j--] = c;
        }
        return S;
    }
};
```
