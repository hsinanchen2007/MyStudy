# 题目要点
1. 不需要返回值
2. 原地修改数组

# 直接使用list.reverse()翻转数组

```python []
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s.reverse()
```

# 双指针

初始化两个指针，一个指向头部，一个指向尾部。
循环交换两个指针指向的元素，直到到达数组的中间位置。

```python []
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        length = len(s)
        head = 0
        tail = length - 1
        half = length // 2
        
        while head < half and tail >= half:
            s[head], s[tail] = s[tail], s[head]
            head += 1
            tail -= 1
```

简化：

循环条件简化为头指针小于尾指针。

```python []
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        length = len(s)
        head = 0
        tail = length - 1
        while head < tail:
            s[head], s[tail] = s[tail], s[head]
            head += 1
            tail -= 1
```

