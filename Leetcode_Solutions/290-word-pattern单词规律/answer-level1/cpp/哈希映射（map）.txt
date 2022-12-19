### 解题思路


### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string,char> word_map;//做一个word到pattern的映射
        char used[128] = {0};//哈希集合
        string word;
        int pos= 0;
        str.push_back(' ');
        for (int i = 0;i<str.length();i++)//遍历每一个字符
        {
            if(str[i]==' ')//遇到分割符
            {
                if(pos == pattern.length())//pattern和str长度不一样
                {
                    return false;
                }
                if(word_map.find(word)==word_map.end())//单词未出现在映射中
                {
                    if(used[pattern[pos]])
                    {
                        return false;
                    }
                    word_map[word]=pattern[pos];
                    used[pattern[pos]]=1;

                }
                else//单词出现在映射中
                {
                    if(word_map[word]!=pattern[pos])
                    {
                        return false;
                    }
                }
                word = "";
                pos++;
            }
            else
            {
                word += str[i];
            }           
        }
        if(pos!=pattern.length())
            {
                return false;
            }
        return true;
    }
};
```