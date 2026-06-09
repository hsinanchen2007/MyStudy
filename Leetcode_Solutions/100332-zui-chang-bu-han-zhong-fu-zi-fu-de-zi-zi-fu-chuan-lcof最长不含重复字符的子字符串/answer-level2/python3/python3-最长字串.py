### 解题思路
没有出现过的字符直接叠加，已出现的要分两种情况讨论：一是与上次出现位置之差小于目前最长子字符串长度，二是大于目前最长子字符串长度，那么就应该将其拼接到子字符串最后位置。
核心算法是（dp），递推公式是f(i) = f(i-1) + 1//f(i) = 与上次出现位置之差，最终时间复杂度是O(n).

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        current_l = 0
        max_l = 0

        position = {}
        
        for i in range(len(s)):
            if s[i] not in position or i - position[s[i]] > current_l:
                current_l += 1
            else:
                if current_l > max_l:
                    max_l = current_l
                
                current_l = i - position[s[i]]
            
            position[s[i]] = i

            if current_l > max_l:
                max_l = current_l

        return max_l

        


```