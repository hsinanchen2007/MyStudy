### 解题思路
以前n个字符和从第n+1个字符开始到字符串结尾作为两个子串然后更换顺序重新组合
![image.png](https://pic.leetcode-cn.com/ac85e691300ae6bd0fc66329c28b0b7790b07465c32d8f0875f7c284c4956141-image.png)
### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
            return s.substr(n,s.length()-n)+s.substr(0,n);
    }
};
```