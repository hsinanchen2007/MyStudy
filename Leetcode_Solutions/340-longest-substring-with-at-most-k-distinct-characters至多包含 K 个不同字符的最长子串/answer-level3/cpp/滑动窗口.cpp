### 解题思路
先找到K个不同的字符串，然后开始滑动，找出最长的字符串

### 代码

```cpp
class Solution {
private:
    bool search(string s, int start, int end, char target) {
        for (int i = start; i <= end; i++)
            if (s[i] == target)
                return true;
        return false;
    }
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0, right;
        int max_len = 0;
        
        int cnt = 0;
        for (right = 0; right < s.size(); right++) {
            if (!search(s, 0, right - 1, s[right]))
                cnt++;
            if (cnt == k) {
                max_len = right + 1;
                break;
            }
        }
        if (cnt < k)
            return right;
        
        while (++right < s.size()) {
            if (!search(s, left, right - 1, s[right])) {
                while (search(s, left + 1, right, s[left]))
                    left++;
                left++;
            }
            max_len = max(right - left + 1, max_len);
        }
        
        return max_len;
    }
};
```