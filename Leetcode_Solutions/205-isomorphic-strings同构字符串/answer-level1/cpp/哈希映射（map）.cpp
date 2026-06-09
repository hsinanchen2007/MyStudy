### 解题思路
方法一：哈希映射map

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> word_map;
        int used[128]={0};
        //遍历字符串
        for(int i = 0;i<s.length();i++)
        {
            if(word_map.find(s[i])==word_map.end())//s[i]不在哈希表里面
            {
                if(used[t[i]])
                {
                    return false;
                }  
                word_map[s[i]]=t[i];//建立映射
                used[t[i]]=1;
            }
            else//s[i]在哈希表里面
            {
                if(word_map[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
```