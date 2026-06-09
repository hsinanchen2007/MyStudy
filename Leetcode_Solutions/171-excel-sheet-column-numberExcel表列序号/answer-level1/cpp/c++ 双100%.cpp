### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int num=0;
        for(int i=0;i<s.size();i++){
            num+=(s[i]-'A'+1)*pow(26,s.size()-1-i);
        }
        return num;
    }
};
```