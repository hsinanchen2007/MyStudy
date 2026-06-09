### 解题思路
只想到了笨方法，思路很简单。
就是挨个检查字符串，是否在最长串内，如果不在就加进去，如果在，就判断一次当前的最长串长度是否是历史最长，然后再删除当前字符串之前的字符（比如：abcedf, 下个是c, 删除后就变成了edf）


### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        vector<char> v;
        for (int i = 0; i < s.length(); i++) 
        {
            int vs = v.size();
            for (int j = 0; j < vs; j++) 
            {
                if (v[j] == s[i]) 
                {
                    if (vs > count) 
                        count = vs;

                    v.erase(v.begin(), v.begin() + j + 1);
                    break;
                }
            }
            v.push_back(s[i]);
        }
        if (v.size() > count) 
            count = v.size();

        return count;
    }
};
```