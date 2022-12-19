使用滑动窗口解决这个问题，用一个map<char,int>来记录元素的下标
窗口的起点和终点为start和end
当遇到重复元素时 start更新为重复元素出现位置的下一个元素
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

            int maxlength = 0;
            map<char, int> mp;
            for (int start = 0, end = 0; end < s.size(); end++)
            {
                if (mp.count(s[end]))
                {
                    start = max(start, mp[s[end]]+1);//更新窗口start
                }
               
                maxlength = max(end - start + 1, maxlength); 
                mp[s[end]] = end;

            }
            return maxlength;
    }
};
```


