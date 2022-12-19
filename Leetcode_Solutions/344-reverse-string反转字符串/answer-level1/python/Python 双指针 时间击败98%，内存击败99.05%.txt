### 解题思路
**方法一：**双指针：头指针，尾指针
当头指针 < 尾指针时，交换头指针指向的元素和尾指针指向的元素
**方法二：**用Python中的list.reverse()函数


### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        head, tail = 0, len(s)-1
        while head < tail:
            s[head],s[tail] = s[tail], s[head]
            head += 1
            tail -= 1
```



### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s.reverse()
```
