### 解题思路
c++真香！unordered_map是hash表实现的，适合这题

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> chars_cnt;
        for(char c:chars)
            ++chars_cnt[c];
        int ans=0;
        bool flag;
        for(string word:words)
        {
            unordered_map<char,int> words_cnt;
            flag=true;
            for(char c:word)
            {
                ++words_cnt[c];
                if(words_cnt[c]>chars_cnt[c])
                {
                    flag=false;
                    break;
                }
            }
            
            if(flag)
                ans+=word.size();
        }
        
        return ans;
    }
    
};
```