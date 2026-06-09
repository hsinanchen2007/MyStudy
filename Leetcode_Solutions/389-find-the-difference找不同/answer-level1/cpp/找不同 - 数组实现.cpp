### 解题思路
1. 做加减法，字符串s[i]出现一次，在数组对应的位置++， 字符串t[i]出现一次，在数组对应的位置--
2. 返回使得数组值为-1的那个字符（新增字符）

### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26] = {0};
        char ans;
        for(int i = 0; i < s.size(); i++)
            hash[s[i] - 'a'] ++;
        for(int i = 0; i < t.size(); i++){
            hash[t[i] - 'a'] --;
            if(hash[t[i] - 'a'] == -1) ans = t[i];
        }
        return ans;
    }
};
```