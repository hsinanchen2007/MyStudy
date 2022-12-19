```
class Solution {
public:
    string intToRoman(int num) {
        char *mp1[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        char *mp10[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        char *mp100[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        char *mp1000[] = {"M", "MM", "MMM"};
        char **mp[] = {mp1,mp10,mp100,mp1000};
        int rate[] = {1,10,100,1000};
        string ret;
        for(int i=3; i>=0; i--)
        {
            if(num >= rate[i])
            {
                ret += mp[i][num/rate[i]-1];
                num %= rate[i];
            }
        }
        return ret;
    }
};
```
