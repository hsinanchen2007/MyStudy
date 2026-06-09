### 解题思路
此处撰写解题思路

### 代码

```python3 []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        usedChar = set()
        i = j = 0
        maxLength = 0
        n = len(s)
        while i < n and j < n:
            if s[j] not in usedChar:
                usedChar.add(s[j])
                j += 1
                maxLength = max(maxLength, j - i)
            else:
                usedChar.remove(s[i])
                i += 1
        return maxLength      

```
```c++ []
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i ++){
            hash[s[i]] ++;  
            while (hash[s[i]] > 1)  hash[s[j ++]] --;  
            res = max(res, i - j + 1);
        }
        return res;
    }
};
```
#### 优化
```python3 []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = maxLength = 0
        usedChar = {}
        for i, c in enumerate(s):
            if c in usedChar and start <= usedChar[c]:
                start = usedChar[c] + 1
            else:
                maxLength = max(maxLength, i - start + 1)
            usedChar[c] = i 
        return maxLength
```
