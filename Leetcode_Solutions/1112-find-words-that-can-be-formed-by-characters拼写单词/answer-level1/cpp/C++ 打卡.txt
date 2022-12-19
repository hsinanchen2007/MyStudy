### 解题思路
map比不上array，惊了
### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int alphacount[26];
        memset(alphacount, 0, sizeof(alphacount));
        int answer = 0;
        for(char c: chars) alphacount[c-'a']++;
        for(string str : words){
            int check[26];
            memcpy(check, alphacount, sizeof(alphacount));
            bool flag = true;
            for(char c : str) if(--check[c-'a'] < 0) flag = false;
            if(flag) answer += str.size();
        }
        return answer;
    }
};
```