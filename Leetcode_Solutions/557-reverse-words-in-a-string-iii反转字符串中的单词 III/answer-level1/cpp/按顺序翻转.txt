```
class Solution {
public:
    void reverse(string& s, int i, int j)
    {
        char c;
        while(i<j)
        {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        while(i<s.size())
        {
            while(j<s.size() && s[j] != ' ')
            {
                j++;
            }
            reverse(s, i, j-1);
            i = ++j;
        }
        return s;
    }
};
```
