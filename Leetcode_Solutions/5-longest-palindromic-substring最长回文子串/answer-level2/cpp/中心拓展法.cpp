### 解题思路
使用中心拓展的方法，复杂度是 O(n^2)

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 1) return "";
        int start = 0, end = 0, len ;
        for (int i=0; i < s.size(); i++){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            len = max(len1, len2);
            if (len > end - start){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start+1, end - start - 1);
    }

    int expandAroundCenter(string s, int left, int right){
        while (left >= 0 && right<s.size() && s[left]==s[right]){
            left--, right++;
        }
        return right - left + 1;
    }
};
```