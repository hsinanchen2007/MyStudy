### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.length()!=s2.length())return false;
        if(s1==s2)return true;
        for(int i=1;i<s2.length();i++){
            if(s2[i] == s1[0]){
                string temp = s2.substr(i,s2.length()-i);
                temp+=s2.substr(0,i);
                if(s1==temp)return true;
            }
        }
        return false;
    }
};
```