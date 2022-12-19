```python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l = [x > target for x in letters]
        return letters[l.index(max(l))]
```
- 返回列表中大于 target 的第一个字符或第一个字符（如果没有比 target 大的字符）
```python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        self.__class__.__getitem__ = lambda self, m: target < letters[m]
        i = bisect.bisect_left(self, True, 0, len(letters) - 1)
        return letters[i] if letters[i] > target else letters[0]
```
- [套路B](https://github.com/cy69855522/Shortest-LeetCode-Python-Solutions/blob/master/README.md#-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE)
```python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l, h = 0, len(letters) - 1
        while l < h:
            m = (l + h) // 2
            if letters[m] > target:
                h = m
            else:
                l = m + 1
        return letters[l] if letters[l] > target else letters[0]
```
- 二分查找 O(logN)
- 所谓的循环只有在数组中所有字符比目标小的时候起作用，只需要在最后增加一个判断就行了