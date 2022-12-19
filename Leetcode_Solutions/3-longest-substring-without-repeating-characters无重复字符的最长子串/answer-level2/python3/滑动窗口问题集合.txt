## [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        max_len = 0
        queue = []

        for right in range(len(s)):
            while s[right] in queue:
                queue.remove(s[left])
                left += 1
            queue.append(s[right])
            max_len = max(max_len, right - left + 1)

        return max_len
```
## [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)
```python
from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        counter = Counter(words)
        one_len = len(words[0])
        all_len = len(words) * one_len
        res = []

        for right in range(len(s) - all_len + 1):
            all_temp = s[right: right + all_len]
            temp = []
            for i in range(0, all_len, one_len):
                temp.append(all_temp[i: i + one_len])
            if counter == Counter(temp):
                res.append(right)
        return res
```
## [53. 最大子序和]()
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        curr_sum = 0

        for i in range(len(nums)):
            if curr_sum < 0:
                curr_sum = 0

            curr_sum += nums[i]
            max_sum = max(max_sum, curr_sum)
        
        return max_sum
```
## [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/submissions/)
```python
from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        counter = Counter(t)
        left = 0
        min_len = len(s) + 1
        dict1 = {}
        res = ""

        def contains(counter, target):
            if len(counter) < len(target):
                return False
            for i in target:
                if i not in counter or counter[i] < target[i]:
                    return False
            return True

        for right in range(len(s)):
            if s[right] in counter:
                dict1.setdefault(s[right], 0)
                dict1[s[right]] += 1
            while contains(dict1, counter):
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    res = s[left: left + min_len]
                if s[left] in counter:
                    dict1[s[left]] -= 1
                    if dict1[s[left]] == 0:
                        dict1.pop(s[left])
                left += 1
        return res
```
## [159. 至多包含两个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/)
```python
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        max_len = 0
        left = 0
        fre_dict = {}

        for right in range(len(s)):
            fre_dict.setdefault(s[right], 0)
            fre_dict[s[right]] += 1
            
            while len(fre_dict) > 2:
                fre_dict[s[left]] -= 1
                if fre_dict[s[left]] == 0:
                    fre_dict.pop(s[left])
                left += 1
            
            max_len = max(max_len, right - left + 1)
        
        return max_len
```
## [209. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)
```python
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        curr_sum = 0
        left = 0
        min_len = len(nums) + 1

        for right in range(len(nums)):
            curr_sum += nums[right]
            while curr_sum >= s:
                min_len = min(min_len, right - left + 1)
                curr_sum -= nums[left]
                left += 1
                
        return min_len if min_len != len(nums) + 1 else 0
```
## [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)
```python
from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        left = 0
        counter1 = Counter(s1)
        counter2 = {}

        for right in range(len(s2)):
            counter2.setdefault(s2[right], 0)
            counter2[s2[right]] += 1
            if right - left + 1 > len(s1):
                key = s2[left]
                counter2[key] -= 1
                if counter2[key] == 0:
                    counter2.pop(key)
                left += 1
            if counter2 == counter1:
                return True
            
        
        return False
```
## [727. 最小窗口子序列](https://leetcode-cn.com/problems/minimum-window-subsequence/)
```python
class Solution:
    def minWindow(self, S: str, T: str) -> str:
        i, j = 0, 0
        start, end = 0, 0
        min_len = len(S) + 1

        while i < len(S):
            if S[i] == T[j]:
                if j == len(T) - 1:
                    end = i 
                    while j >= 0:
                        if S[i] == T[j]:
                            j -= 1
                        i -= 1
                    i += 1
                    if end - i + 1 < min_len:
                        min_len = end - i + 1
                        start = i
                j += 1
            i += 1
        
        return S[start: start + min_len] if min_len != len(S) + 1 else ""
```

## [904. 水果成篮](https://leetcode-cn.com/problems/fruit-into-baskets/)
```python
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        max_len = 0
        left = 0
        queue = {}

        for right in range(len(tree)):
            queue.setdefault(tree[right], 0)
            queue[tree[right]] += 1
            while len(queue) > 2:
                queue[tree[left]] -= 1
                if queue[tree[left]] == 0:
                    queue.pop(tree[left])
                left += 1
            max_len = max(max_len, right - left + 1)

        return max_len
```

