### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        //边界条件
        if(s.empty())
        {
            return ' ';
        }
        //设置一个字符哈希:字符哈希可以统计字符出现的频率
        vector<int> char_set(128);
        for(int i=0; i < s.size(); i++)
        {
            char_set[s[i]]++; //对应ASCLL码的位置自增1
        }
        for(int i=0; i < s.size(); i++)
        {
            if(char_set[s[i]] == 1)
            {
                return s[i];
            }
        }
        return ' ';
    }
};

```