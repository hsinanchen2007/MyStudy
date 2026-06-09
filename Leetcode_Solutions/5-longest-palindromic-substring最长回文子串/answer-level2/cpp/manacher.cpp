### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())return "";
        string t = "#";
        for(int i = 0; i < s.size(); ++i)
        {
            t += s[i];
            t += "#";
        }
        int n = t.size();
        int p[n], c = -1, r = -1, resMax = INT_MIN, resIndex = -1;
        for(int i = 0; i < n; ++i)
        {
            p[i] = r > i ? min(r - i, p[2 * c - i]) : 1;
            while(i + p[i] < n && i - p[i] > -1)
            {
                if(t[i + p[i]] == t[i - p[i]])
                    p[i]++;
                else
                    break;
            }
            if(r < i + p[i])
            {
                r = i + p[i];
                c = i;
            }
            if(resMax < p[i])
            {
                resMax = p[i];
                resIndex = i;
            }
        }
        return s.substr((resIndex - resMax + 1) / 2, resMax - 1);
    }
};
```