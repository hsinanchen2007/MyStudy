本题的解法与“3.无重复字符的最长子串”相似，采用滑动窗口遍历满足条件的所有情况。
特殊的是，在滑动窗的头部右移时，需要判断当前滑动窗中所包含字符类别数curK是否得到更新。本方法采用STL中的map对每类字符进行计数。

```
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> slideSet;
        int maxLength = 0;
        int curLength = 0;
        int start = 0;
        int curK = 0;

        if (k < 1)
            return 0;

        for (int end = 0; end < s.size(); end++)
        {
            // 滑动窗中包含新元素
            if (slideSet[s[end]])
            {
                slideSet[s[end]]++;
                curLength++;
                maxLength = curLength>maxLength ? curLength : maxLength;
            }
            else
            {
                // 添加新元素
                if (curK < k)
                {
                    slideSet[s[end]] = 1;
                    curK++;
                    curLength++;
                    maxLength = curLength>maxLength ? curLength : maxLength;
                }
                // 删除前端元素
                else
                {
                    while(slideSet[s[start]] != 1)
                    {
                        slideSet[s[start]]--;
                        start++;
                        curLength--;
                    }
                    // 当前start对应元素只在滑动窗中存在一个
                    slideSet[s[start]] = 0;
                    start++;
                    curLength--;

                    slideSet[s[end]] = 1;
                    curLength++;
                    maxLength = curLength>maxLength ? curLength : maxLength;
                }
            }
        }
        return maxLength;
    }
};
```
