### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseStr(string &s, int k) {
    string s1="";
    for (int i=0; i<s.length(); i+=2*k) {
        if (s.length()-i<k) reverse(s.begin()+i, s.end());
        else{
            reverse(s.begin()+i, s.begin()+i+k);
        }
    }
    s1=s;
    return s1;
}
};
```