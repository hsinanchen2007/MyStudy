![image.png](https://pic.leetcode-cn.com/14327e16e7abe09ec7871414cd5e9a78b05636a591230726edb4c3291bd9f109-image.png)

```
class Solution {
public:
    inline string reverseWords(string s) {
        size_t prevPos = 0;
        size_t currPos = 0;
        while ((currPos = s.find(' ', prevPos)) != std::string::npos) {
            std::reverse(s.begin() + prevPos, s.begin() + currPos);
            prevPos = currPos + 1;
        }
        std::reverse(s.begin() + prevPos, s.end());
        return std::move(s);
    }
};
```
