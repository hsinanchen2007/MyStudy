### 解题思路
一个题目写半个小时，基础太弱了

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) 
    {
        string _s = "aeiouAEIOU";

        int _begin = 0, _end = s.size() - 1;
        
        char cbegin = s[_begin];
        char cend = s[_end];

        while(_begin < _end)
        {
            bool _c = true;
            if (_s.find(cbegin) == -1)
            {
                _c = false;
                cbegin = s[++_begin];
            }
            if (_s.find(cend) == -1)
            {
                _c = false;
                cend = s[--_end];
            }
            if (!_c)
            {
                continue;
            }

            s[_begin] = cend;
            s[_end] = cbegin;

            cbegin = s[++_begin];
            cend = s[--_end];
        }
        return s;
    }
};
```