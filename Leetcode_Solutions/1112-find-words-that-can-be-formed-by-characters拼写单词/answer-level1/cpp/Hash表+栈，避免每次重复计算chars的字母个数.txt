一般的思路便是统计chars中每个字母的个数，然后循环遍历检查每个word中的字母是否在chars中出现，如果出现则对对应的字母数减1，否则break出循环，即该单词不能拼写成功。
以上过程存在一个问题：遍历每个字母的时候，都需要重新统计chars中每个字母的个数，当chars的长度远远大于word的长度时，内循环的计算都浪费在统计chars的字母个数上，那么优化点来了，能不能不重复统计呢？答案是肯定的，通过stack或者int array 来解决，这里就不哔哔了，直接看代码吧。

stack 版本
```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int mp[26] = {0};
        int len = 0;
        stack<int> stk;
        for(int i = 0; i < chars.size(); i++)
            mp[chars[i] - 'a']++;
        for(int i = 0; i < words.size(); i++)
        {
            int j = 0;
            for(; j < words[i].size(); j++)
            {
                if(mp[words[i][j] - 'a'] > 0)
                {    
                    mp[words[i][j] - 'a']--;
                    stk.push(words[i][j] - 'a');
                }
                else break;
            }
            while(!stk.empty())
            {
                mp[stk.top()]++;
                stk.pop();
            }
            if(j == words[i].size())
                len += j;
        }
        return len;
    }
};

```

int array 版本
```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int mp[26] = {0};
        int inv[chars.size()] = {0};
        int len = 0;
        for(int i = 0; i < chars.size(); i++)
            mp[chars[i] - 'a']++;
        for(int i = 0; i < words.size(); i++)
        {
            int j = 0;
            int p1 = 0;
            for(; j < words[i].size(); j++)
            {
                if(mp[words[i][j] - 'a'] > 0)
                {    
                    mp[words[i][j] - 'a']--;
                    inv[p1++] = (words[i][j] - 'a');
                }
                else break;
            }
            while(--p1 >= 0)
                mp[inv[p1]]++; 
            if(j == words[i].size())
                len += j;
        }
        return len;
    }
};
```