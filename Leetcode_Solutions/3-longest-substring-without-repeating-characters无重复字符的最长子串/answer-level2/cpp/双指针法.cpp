前部指针j指向要比较的元素，后部指针i指向比较队列尾部。每次比较s[j]时如果出现重复元素s[t]，则将i换为t+1后继续比较。
```cpp
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i{}, j{1};
        int maxstr{s.size()==0?0:1};

        while (j < s.size()&&i<s.size())
        {
            auto tmp = s.substr(i, j - i);
            size_t t = tmp.find(s[j]);
            if ( t != string::npos)
            {
                j++;
                i += t+1;
            }
            else
            {
                j++;
            }   
            maxstr = max(maxstr, j - i);
        }
        return maxstr;
    }
};
```
