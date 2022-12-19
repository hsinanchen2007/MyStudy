### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)return "";
        return (str1+str2).substr(0,__gcd((int)str1.length(),(int)str2.length()));
    }
};
```