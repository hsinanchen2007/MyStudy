### 解题思路
1.遍历字符串，使用hash_map做计数器给字符串每一个字符做计数。
2.再遍历字符串，检索到第一个计数器为1的字符，并返回字符的下标。

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> char_counts;
        for(int i = 0;i < s.length();i++){
            char_counts[s[i]]++;
        }
        
        for(int i = 0;i < s.length();i++){
            if(char_counts[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
```