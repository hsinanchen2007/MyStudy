### 题目描述
![image.png](https://pic.leetcode-cn.com/fe02dfb27ef014224ae9177f0f108a7bd8d332912c54c1ef5f2baaecf91acc28-image.png)


### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        if(s.size() == 1)
            return 1;

        int max = 1;
        int i = 0, j = 1, k;
        while(j < s.size())
        {
            for(k = i;k < j;k++)
            {
                if(s[k] == s[j])
                {
                    i = k + 1;
                    break;
                }
            }
            j++;
            if(j-i > max)
                max = j-i;
        }
        return max;
    }
};
```