### 解题思路
此处撰写解题思路
![2020-04-07 20-44-59 的屏幕截图.png](https://pic.leetcode-cn.com/5dfe9017565db2c924e98dc69806837e4b0dc2d6144bdba94f3e4d849607e3d8-2020-04-07%2020-44-59%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> src(128, -1);
        vector<int> dest(128, -1);

        for (int i = 0; i < s.length(); i++) {

            if (src[s[i]] != -1 && src[s[i]] != t[i]) return false;
            if (dest[t[i]] != -1 && dest[t[i]] != s[i]) return false; 

            src[s[i]] = t[i];
            dest[t[i]] = s[i];
        }

        return true;
    }
};
```