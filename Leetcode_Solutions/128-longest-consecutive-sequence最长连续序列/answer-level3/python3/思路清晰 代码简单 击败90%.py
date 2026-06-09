![image.png](https://pic.leetcode-cn.com/133a3161485e6c82b8654479b519dc9a6e27fe233d41eb8ad88f6766847c658d-image.png)
### 解题思路
建立一个集合，每次从集合中pop出一个元素x，不断由这个元素向前找，再从x开始不断向后找，找到的过程中不断删掉元素

### 代码

```python3
class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0
        num_set = set(nums)

        # 集合为空的时候结束
        while num_set:
            # 弹出一个元素
            num = num_set.pop()

            current_streak = 1
            # 向前找
            current_num = num - 1
            while current_num in num_set:
                num_set.remove(current_num)
                current_streak += 1
                current_num -= 1
            # 向后找
            current_num = num + 1
            while current_num in num_set:
                num_set.remove(current_num)
                current_streak += 1
                current_num += 1
                
            longest_streak = max(longest_streak, current_streak)

        return longest_streak

```