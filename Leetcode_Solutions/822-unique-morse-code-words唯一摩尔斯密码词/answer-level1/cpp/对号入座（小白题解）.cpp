
### 代码

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.empty()) return 0;

        vector<string> help={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",                                  "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",                              "...-",".--","-..-","-.--","--.."};
        set<string> use;

        for(string word:words)
        {
            string temp="";
            for(char c:word)
                temp+=help[c-'a'];
            use.insert(temp);
        }

        return use.size();
    }
};
```