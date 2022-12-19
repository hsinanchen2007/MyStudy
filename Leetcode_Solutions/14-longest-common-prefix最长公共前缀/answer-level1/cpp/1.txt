### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1)
        {
            return "";
        }
        else if (strs.size() == 1)
        {
            return strs[0];
        }
        int length = 0;
        char temp;
        bool over = false;
        while(!over)
        {
            for(auto i = 0; i < strs.size(); i++)
            {
                if(strs[i].length() == 0 || strs[i].length() <= length)
                {
                    over = true;
                    break;
                }
                if(i == 0)
                {
                    temp = strs[i].at(length);
                }
                else
                {
                    if(strs[i].at(length) != temp)
                    {
                        over = true;
                        break;
                    }
                }
            }
            if(!over)
                length++;
        }

        if(length > 0)
            return strs[0].substr(0, length);
        else
            return "";
    }
};
```