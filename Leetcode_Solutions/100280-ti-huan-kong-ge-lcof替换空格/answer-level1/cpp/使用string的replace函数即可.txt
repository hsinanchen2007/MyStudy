### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                s.replace(i,1,"%20");
            }
        }
        return s;
        
    }
};
```