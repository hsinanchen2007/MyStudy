### 解题思路
原题是不占用额外空间

![](https://pic.leetcode-cn.com/586d3e3277914aee6027f593277b117170040e124cee702e64ddf51fdbc0aa6f-%5D3HU%5B72H~4Z8P@G9_UJ5~$P.png)


### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        // 原地修改
        auto it = s.begin();
        string _s = "%20";
        while (it != s.end()) {
            if (*it == ' ') {
                s.erase(it);
                it = s.insert(it, _s.begin(), _s.end());
            }
            else ++it;
        }
        return s;
    }
};
```