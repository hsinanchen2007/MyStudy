### 解题思路
通过维护一个hash 表，key 是字符，value是索引。当出现重复的字符时更新字串的索引和hash对应的value。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map_index;
        int max_length = 0;
        int i = 0;
        map_index[s[i]] = i;
        for(int j = i + 1; j < s.size(); ++j){
            if(map_index.find(s[j]) != map_index.end()){
                if(map_index[s[j]]  >= i){
                    max_length = std::max(j - i, max_length);
                    i = map_index[s[j]] + 1;
                }
                map_index[s[j]] = j;

            }else{
                map_index[s[j]] = j;
            }
        }
        
        max_length = std::max<int>(max_length, s.size() - i);
        return max_length;

        
    }
};
```