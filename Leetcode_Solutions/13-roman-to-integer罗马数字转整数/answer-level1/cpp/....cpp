### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int romanToInt(string& s) {
        int result = 0;
        map<string, int> spc;
        spc["IV"] = 4;
        spc["IX"] = 9;
        spc["XL"] = 40;
        spc["XC"] = 90;
        spc["CD"] = 400;
        spc["CM"] = 900;
        spc["I"] = 1;
        spc["V"] = 5;
        spc["X"] = 10;
        spc["L"] = 50;
        spc["C"] = 100;
        spc["D"] = 500;
        spc["M"] = 1000;
        for(int i = 0; i < s.length(); i++)
        {
            if(i < s.length() and spc.count(s.substr(i, 2)) > 0)
            {
                result += spc[s.substr(i, 2)];
                i++;
            }
            else
            {
                result += spc[s.substr(i, 1)];
            }
        }
        return result;
    }
};
```