### 解题思路
合并了筛选步骤，优化了以下内存消耗
### 代码

```cpp
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string temp;
        vector<string> rea;
        vector<string> out;
        int q = -1;
        for(int i = 0;i<=text.length();++i)
        {
            if(text[i] == ' ' || text[i] == '\0')//i == text.length()
            {
                rea.push_back(temp);
                ++q;
                if(q >= 2 && rea[q-1] == second && rea[q-2] == first)
                {
                    out.push_back(temp);
                }
                temp = "";
            }   
            else
            {
                temp.push_back(text[i]);
            }
        }
        return out;
    }
};
```