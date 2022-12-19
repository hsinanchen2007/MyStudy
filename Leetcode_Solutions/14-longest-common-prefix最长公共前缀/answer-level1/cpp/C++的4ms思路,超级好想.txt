### 解题思路
此处撰写解题思路
先找到所有数组里面最小的那个长度，公共子串一定比它要短。
初始化返回字符串str为空。
从零开始遍历，如果全部一样就字符串相加，只要不等就返回，最终返回结果即可。
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=0)
        return "";
        string str="";
        int min=INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()<min)
            min=strs[i].size();
        }
        for(int i=0;i<min;i++)
        {
            bool s=true;
            for(int j=0;j<strs.size()-1;j++)
            {
                if(strs[j][i]!=strs[j+1][i])
                {
                s=false;
                break;
                }
            }
            if(s==false)
            {
                break;
            }
            else{
                str+=strs[0][i];
            }
        }
        return str;
    }
};
```