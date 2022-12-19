### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        bool flag[26] = {false};
        int len = astr.length();
        for(int i = 0; i < len; i++){
            if(flag[astr[i]-'a']){
                return false;
            }
            flag[astr[i]-'a'] = true;
        }
        return true;
    }
};
```