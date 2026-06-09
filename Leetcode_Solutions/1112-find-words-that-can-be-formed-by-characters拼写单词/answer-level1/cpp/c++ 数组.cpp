### 解题思路
用一个长度为26的数组ch保存chars中每个字母出现的次数
遍历words中的每个单词，同样用一个长度为26的数组wd保存单词中每个字母出现的次数，先在结果res中加上该单词的长度，再遍历数组，如果ch中的元素都大于等于wd中的元素，则表明该单词可以由chars构成。否则的话，在res中减去该单词的长度，跳出循环。

如果感觉到有启发，欢迎点赞或评论😄

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        int ch[26]={0};
        for(char c:chars)
            ch[c-'a']++;
        
        for(string word:words)
        {
            int wd[26]={0};
            for(char c:word)
                wd[c-'a']++;
            res+=word.size();
            for(char c:word)
            {
                if(ch[c-'a']<wd[c-'a'])
                {
                    res-=word.size();
                    break;
                }    
            }
        }
        return res;
    }
};
```