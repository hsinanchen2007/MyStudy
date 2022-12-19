### 解题思路
已短的那个的长度作为遍历次数

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;

        int aSize = haystack.size();
        int bSize = needle.size();

        if (aSize < bSize)
            return  -1;

        for (int gap = 0; gap < aSize - bSize + 1; ++gap)
        {
            //以短的那个的长度作为遍历长度
            int ite = 0;
            for (; ite < needle.size(); ++ite)
            {
                if (haystack[gap + ite] != needle[ite])
                    break;
            }

            if (ite == needle.size())
                return gap;

        }

        return -1;
    }
};
```