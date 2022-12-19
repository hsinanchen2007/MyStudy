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
    string reverseStr(string s, int k) {
        int i = 0;
        int j = k;
        int end = s.size();
        while(i<end-1)
        {
            j = i + k;
            if(j > end)
                j = end;
            reverse(s, i, j-1);
            i += 2*k;
        }
        return s;
    }
};
```
