### 解题思路
![image.png](https://pic.leetcode-cn.com/827215016e7a7e8a53f60102200014619ec0234a58586075bcd7e9a9c74c58be-image.png)

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int left = 0,right = 0;
        int maxlen = 0;
        while(right < s.size())
        {
            char c = s[right];
            window[c]++;
            right++;
            
            while(window[c] > 1)
            {
                char c2 = s[left];
                window[c2]--;
                left++;
            }

            maxlen = max(maxlen,right - left);

        }
        return maxlen;
    }
};
```