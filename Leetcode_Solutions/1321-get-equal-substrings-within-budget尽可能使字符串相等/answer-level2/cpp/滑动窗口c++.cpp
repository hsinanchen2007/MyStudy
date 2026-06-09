~~~c
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
    int res = 0, l = 0, sum = 0;
    for(int i = 0; i < t.size(); i++)
    {
        sum += abs(s[i] - t[i]);
        while(sum > maxCost)
        {
            sum -= abs(s[l] - t[l]);
            l++;
        }
        res = max(res, i - l + 1);
    }
    return res;   
    }
};
~~~