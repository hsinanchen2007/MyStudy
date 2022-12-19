### 解题思路
这是官方思路三的代码，利用集合去重以及插入、查找时间复杂度为O(1)的特性，实现了O(n)的时间复杂度。具体过程是每次找到一个连续集合的首元素，通过cur-1不断试探，然后while循环把连续元素都给找到。

### 代码

```python3
class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak
```