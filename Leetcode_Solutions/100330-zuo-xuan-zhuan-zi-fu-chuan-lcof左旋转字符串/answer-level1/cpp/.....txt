### 解题思路
此处撰写解题思路
用substr函数就可以了，然后相加就行了emmmmm，很简单。
### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        basic_string<char>str1=s.substr(0,n);
        basic_string<char>str2=s.substr(n,s.length()-1);
        return str2+str1;
    }
};
```