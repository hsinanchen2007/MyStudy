### 解题思路

1. 这道题目最大的问题在于我误解了题意(+_+)?，没有仔细看示例。题目的意思是chars中的每个char在针对每个单词时只能用一次，而不是针对整个words只能用一次。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int i, j, sum = 0;
        unordered_map<char, int> table;

        for(char c:chars)  table[c]++;
        for(string s:words){
            for(j = 0; j < s.size(); j++){
                if(table[s[j]] > 0)  table[s[j]]--;
                else{
                    while(--j >= 0)  table[s[j]]++;
                    break;
                }
            }
            if(j == s.size()){
                sum += s.size();
                while(--j >= 0)  table[s[j]]++;
            }  
        };
        return sum;
    }
};
```



