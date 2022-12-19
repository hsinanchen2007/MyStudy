### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        string str;
        int step = 0;
        int round = 0;
        while(i < a.size() || i < b.size())
        {
            if(i < a.size() && i < b.size())
            {
                round = ((a[i] - '0') + (b[i] - '0') + step) % 2;
                step = ((a[i] - '0') + (b[i] - '0') + step) / 2;    
                str = to_string(round) + str;
            }
            else if(i < a.size())
            {
                round = ((a[i] - '0') + step) % 2;
                step = ((a[i] - '0') + step) / 2;    
                str = to_string(round) + str;
            }
            else
            {
                round = ((b[i] - '0') + step) % 2;
                step = ((b[i] - '0') + step) / 2;    
                str = to_string(round) + str;
            }
            i++;
        }
        if(step != 0)
            str = to_string(step) + str;
        return str;
    }
};
```