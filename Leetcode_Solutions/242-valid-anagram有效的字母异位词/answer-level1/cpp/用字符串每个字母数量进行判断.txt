### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0),vec(26,0);
        for(int j=0;j<s.size();j++){
            v[(int)(s[j]-'a')]++;
        }
        for(int j=0;j<t.size();j++){
            vec[(int)(t[j]-'a')]++;
        }
        if(v==vec)  return true;
        else return false;
    }
};
```题目规定仅有小写字母，所以可以直接通过判断s和t的字母数量是否相等。