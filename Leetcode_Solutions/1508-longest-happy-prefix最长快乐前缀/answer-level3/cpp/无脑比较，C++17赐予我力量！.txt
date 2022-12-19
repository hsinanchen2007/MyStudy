无脑暴力比较
```cpp
class Solution 
{
public:
    string longestPrefix(string s) 
    {
        string_view prefix = s;
        string_view suffix = s;
        for (int i = s.size() - 1; i > 0; --i)
        {
            suffix.remove_prefix(1);
            prefix.remove_suffix(1);
            if (prefix == suffix)
            {
                return string(prefix);
            }
        }

        return string();
    }
};
```

-----
C++17版本太高，也可以改用C++14
```cpp
class Solution
{
public:
    string longestPrefix(string s)
    {
        auto prefixEnd = s.end();
        auto suffixBegin = s.begin();
        for (int i = s.size() - 1; i > 0; --i)
        {
            --prefixEnd;
            ++suffixBegin;
            if (equal(s.begin(), prefixEnd, suffixBegin, s.end()))
            {
                return string(s.begin(), prefixEnd);
            }
        }

        return string();
    }
};
```