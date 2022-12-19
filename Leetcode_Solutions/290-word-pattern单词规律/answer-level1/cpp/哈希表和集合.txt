### 解题思路
![1584778910(1).png](https://pic.leetcode-cn.com/8ab0505ff1ff9db83399ec00c3e7079ee97e864da084eaf878ece11d626e93ef-1584778910\(1\).png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.size()==0&&str.size()!=0) return false;
        unordered_map<char,string> mymap;
        int j=-1;
        for(int i=0;i<pattern.size();i++)
        {
            int k=j+1;
            if(i!=pattern.size()-1)
            {
                for(;k<str.size();k++)
                {
                    if(str[k]==' ') 
                    {
                        break;
                    }
                }
            } 
            if(k==str.size()) return false;
            if(i==pattern.size()-1) k=str.size();
            //j+1,k-1
            if(mymap.find(pattern[i])==mymap.end())
            {
                mymap[pattern[i]] = str.substr(j+1,k-j-1);
            }
            else
            {
                if(mymap[pattern[i]]!=str.substr(j+1,k-j-1)) return false;
            }
            j = k;
        }
        set<string> myset;
        for(unordered_map<char, string>::iterator it=mymap.begin();it!=mymap.end();it++)
        {
            myset.insert(it->second);
        }

        return myset.size()==mymap.size();
    }
};
```