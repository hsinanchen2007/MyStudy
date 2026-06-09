

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> letters(26,0);
        vector<int> tmp;   
        int count = 0;
        for(char c : chars) letters[c-'a']++;
        for(auto s : words)
        {
            tmp = letters;
            int i = 0;
            while(i<s.length())
            {
                if(tmp[s[i]-'a'] == 0) break;
                tmp[s[i++]-'a']--;
            }
            if(i==s.length()) count += i;
        }
        return count;

    }
};
```