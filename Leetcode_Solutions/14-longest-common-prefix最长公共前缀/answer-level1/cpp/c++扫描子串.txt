### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        {
            return "";
        }
        string prefix=strs[0]; //假设一直公共的前缀
        for(int i=1;i<strs.size();i++)
        {
            while(strs[i].find(prefix)!=0)
            {
                if(prefix.size()==0){
                    return "";
                }
                else
                {
                    prefix=prefix.substr(0,prefix.size()-1);
                }
            }
        }
        return prefix;
    }
};
```