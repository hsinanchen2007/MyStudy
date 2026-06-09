### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int flag[26] = {0};
        int len1 = s1.length(),len2 = s2.length();
        if(len1 != len2)
            return false;
        for(int i = 0; i < len1; i++){
            flag[s1[i]-'a']++;
        }
        for(int i = 0; i < len2; i++){
            flag[s2[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(flag[i]){
                return false;
            }
        }
        return true;
    }
};
```