### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) 
    {
        map<int, string> m;
        m[1] = "I";
        m[4] = "IV";
        m[5] = "V";
        m[9] = "IX";
        m[10] = "X";
        m[40] = "XL";
        m[50] = "L";
        m[90] = "XC";
        m[100] = "C";
        m[400] = "CD";
        m[500] = "D";
        m[900] = "CM";
        m[1000] = "M";

        string ans = "";

        for(auto it  = m.rbegin(); it != m.rend(); it++)
        {
            int n = it->first;
            if(n <= num)
                while(num - n >= 0)
                {
                    num -= n;
                    ans += it->second;
                }
        }

        return ans;
        
    }
};
```