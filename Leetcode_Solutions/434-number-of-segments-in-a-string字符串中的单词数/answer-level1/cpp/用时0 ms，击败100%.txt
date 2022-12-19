### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/a825c36dd7794aa4e7c1c507c92f392d8009b6be62118be23ae88b153590b779-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int len = s.size();
        //以空开头的字符串count初始值应为0，非空开头的字符串count初始值应为1
        if (len > 0 && s[0] != ' ')
            ++count;
        for (int i = 0; i < len - 1; ++i)
        {
            if (s[i] == ' ' && s[i + 1] != ' ')
                ++count;
        }
        return count;
    }
};
```