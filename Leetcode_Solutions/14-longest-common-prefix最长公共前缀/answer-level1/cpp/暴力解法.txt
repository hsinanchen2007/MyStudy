### 解题思路
算是一次通过的暴力解法

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0)
            return "";

        string str = strs[0];
        for(int i = 0; i < len; i++)
        {
            if(strs[i].size() < str.size())
            {
                str = strs[i];
            }
        }

        int max = str.size();
        for(int j = 0; j < len; j++)
        {
            int temp = 0;
            for(int k = 0; k < str.size(); k++)
            {
                if(strs[j][k] == str[k])
                {
                    ++temp;
                }else if(temp == 0){
                    return "";
                }else{
                    if(temp < max)
                    {
                        max = temp;
                    }
                    break; 
                }       
            }
        }

        return str.substr(0, max);
    }
};
```