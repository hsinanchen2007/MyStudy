### 解题思路
示例实际返回的是False,  此题并没有说忽略大小写、空格等

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        map<char, int> m;

        for(int i = 0; i < s.size(); ++i)
        {
            ++m[s.at(i)];
        }

        int odd_count = 0;
        for(auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if(iter->second % 2 != 0)
            {
                ++odd_count;
            }
        }

        if(s.size() % 2 == 0)
        {
            if(odd_count == 0) //字符次数全为偶数次
                return true;
        }
        else
        {
            if(odd_count == 1) //奇数次的字符仅有一个
                return true;
        }
        return false;
    }
};
```