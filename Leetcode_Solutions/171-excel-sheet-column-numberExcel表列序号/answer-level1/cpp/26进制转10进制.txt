```
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        int n = s.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {
            sum += pow(26,n) * (s[i]-'A'+1);
            n--;
        }
        return sum;
    }
};
```
