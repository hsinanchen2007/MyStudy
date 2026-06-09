### 头文件
#include <string>
#include <map>

### 代码

```cpp
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int len1 = s.size(), len2 = t.size();
        if (len1 < len2 || len2 == 0)
            return "";
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;
        map<char, int> map1, map2;
        int flag = 0; //记录符合要求的元素个数
        for (auto c : t)
            map1[c]++;

        while (right <= len1)
        {
            if (map1.count(s[right]))
            {
                map2[s[right]]++;
                if (map2[s[right]] == map1[s[right]])
                    flag++;
            }
            while (flag == map1.size())
            {
                if (right - left < minLen)
                {
                    minLen = right - left;
                    start = left;
                }
                if (map1.count(s[left]))
                {
                    if (map2[s[left]] == map1[s[left]])
                        flag--;
                    map2[s[left]]--;
                }
                left++;
            }
            right++;
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(start, minLen + 1);
    }
};
```