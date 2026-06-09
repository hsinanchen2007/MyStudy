
### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> help(26,0);
        for(char c:s)
            help[c-'a']++;
        for(char c:s)
            if(help[c-'a']==1) return c;
        return ' ';
        /*
        unordered_map<char,int> help;
        for(char c:s) help[c]++;
        for(char c:s){
            if(help[c]==1) return c;
        }
        return ' ';
        */
    }
};
```