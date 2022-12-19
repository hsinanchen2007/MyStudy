### 解题思路
题目的举例不太恰当，还是二分查找，寻找右边界，然后前挪一步，相当于取到大于target的最小值

### 代码

```python
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        n = len(letters)
        left, right = 0, n
        while left < right:
            mid = (left + right) // 2
            if letters[mid] == target:
                left = mid + 1
            elif letters[mid] < target:
                left = mid + 1
            elif letters[mid] > target:
                right = mid
        return letters[left % n]
```