```
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for(int i=0;i<t.length();i++)
        {
            sum += t[i];
            if(i < s.length())
                sum -= s[i];
        }
        return (char)sum;
    }
};
```