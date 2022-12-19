### 解题思路
熟悉unoredered map的数据结构。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       unordered_map<char,int> chars_map;
       int ans = 0;
       for (auto alpha :chars){
           chars_map[alpha]++;
       }
       for(auto word:words){
           bool is_ans = true;
           unordered_map<char,int> word_map;
           for(auto alpha :word){
               word_map[alpha]++;
           }
           for(auto alpha:word){
               if(word_map[alpha]>chars_map[alpha]){
                   is_ans = false;
                   break;
               }
           }
           if(is_ans){
               ans += word.length();
           }
       }
       return ans;
    }
};
```