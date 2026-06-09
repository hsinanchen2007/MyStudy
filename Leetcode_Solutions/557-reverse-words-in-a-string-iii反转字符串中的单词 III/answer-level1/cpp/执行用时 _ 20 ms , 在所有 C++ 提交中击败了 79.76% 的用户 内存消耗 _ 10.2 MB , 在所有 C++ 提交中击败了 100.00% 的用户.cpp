### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
    for (int i=0; i<s.length();i++) {
        int begin=i,end;
        while (s[i]!=' '&&s[i]!='\0') {
            i++;
        }
        end=i;
        reverse(s.begin()+begin,s.begin()+end);
    }
    string s1=s;
    return s1;
}
};
```