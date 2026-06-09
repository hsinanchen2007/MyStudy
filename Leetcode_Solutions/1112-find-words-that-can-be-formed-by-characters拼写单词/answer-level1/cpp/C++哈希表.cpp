### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> record;
        for(char c:chars)
        {
            record[c]++;
        }

        int len_sum=0;
        for(string word:words)
        {
            map<char,int> mp;
            for(int i=0; i<word.size(); ++i)
            {
                mp[word[i]]++;
            }

            bool is_ans=true;
            for(auto m:mp)
            {
                if(m.second > record[m.first])
                {
                    is_ans=false;
                    break;
                }
            }
            if(is_ans) len_sum+=word.size();
        }

        return len_sum;
    }
};
```