### 解题思路
![image.png](https://pic.leetcode-cn.com/3c811851643057e353394b673185fe721042b42447ab239c262ca49482f60927-image.png)


### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s.append(s,0,n);
        return s.substr(n);
    }
};
```