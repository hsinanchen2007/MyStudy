#### 1,本来的想法是：遍历每个Word，针对每个word中的每个字母，再遍历一遍chars，如果相等的话，计数器加一。如果最后计数器的值等于word的长度的话，成功拼写。同时设置bool mark[]用来标记已经使用过的chars中的字母。

#### 2，因为对字符串的遍历不熟悉，所以看了官方解答，发现思路好清晰优雅：只要`word`中每个字母的数量<=`chars`中每个字母的数量，就可以完成拼写。其实这个题是考察`unordered_map`的hash表应用。

#### 3，另外，学到了如何遍历字符串数组 `for(string word:words)`

```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        unordered_map<char,int>chars_cnt;
        for(char c:chars)
            chars_cnt[c]++;
        for(string word:words){
            unordered_map<char,int>word_cnt;
            for(char c:word)
                word_cnt[c]++;
            bool flag=true;
            for(char c:word){
                if(chars_cnt[c]<word_cnt[c])//不足以拼写单词
                    {
                        flag=false;
                        break;
                    }
            }
            if(flag)
             ans=ans+word.length();
        }
        return ans;
    }
};
```