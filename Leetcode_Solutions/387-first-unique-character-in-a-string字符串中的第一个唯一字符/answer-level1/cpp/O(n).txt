### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int ans[26]={0};
        int buf;
        for(int i=0;i<s.length();i++){
            ans[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(ans[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};
```