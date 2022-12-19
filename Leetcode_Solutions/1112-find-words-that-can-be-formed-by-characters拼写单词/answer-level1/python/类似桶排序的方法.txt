### 解题思路
计算chars每个字符出现的次数。
分别计算words每个字符串中每个字母（chars中是否满足），如果chars中的字符可以满足字符串的拼写，sum累加，否则不能拼写该字符串。
时间复杂度O(max(len(words),len(chars)))

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        nums = dict()
        for c in chars:
            if c in nums.keys():
                nums[c] = nums[c] + 1
            else:
                nums[c] = 1
        sum = 0
        for item in words:
            nums_copy = nums.copy()
            flag = True
            for c in item:
                if c in nums_copy.keys():
                    nums_copy[c] = nums_copy[c] - 1
                    if nums_copy[c] < 0:
                        flag = False
                        break
                else:
                    flag = False
                    break
            if flag:
                sum = sum + len(item)
        return sum
```