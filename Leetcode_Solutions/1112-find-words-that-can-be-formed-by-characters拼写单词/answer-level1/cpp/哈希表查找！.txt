### 解题思路

哈希表查找

### 代码

```cpp
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int char_num[26] = {0};
        fill(char_num, char_num + 26, 0);
        int word_num[26] = {0};
        
        for(char ch:chars)
        {
            char_num[ch-'a']++;
        }

        int ans = 0;
        for (string word : words)
        {
            fill(word_num, word_num + 26, 0);

            for(char ch:word)
            {
                word_num[ch-'a']++;
            }

            bool flag = true;
            for(char ch:word)
            {
                if(word_num[ch-'a'] > char_num[ch-'a'])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ans += word.length();
            }
        }
        return ans;
    }
};
```