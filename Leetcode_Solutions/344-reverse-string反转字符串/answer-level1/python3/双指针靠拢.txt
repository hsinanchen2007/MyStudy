### 解题思路
1. 两个指针一头一尾
2. 同时向中间靠拢，并交换两者的值
3. 直到head和tail相遇为止

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        #双指针方法，一头一尾
        head,tail = 0,len(s)-1
        while head <tail:
            s[head],s[tail] = s[tail],s[head]
            head += 1
            tail -= 1
        return s
```