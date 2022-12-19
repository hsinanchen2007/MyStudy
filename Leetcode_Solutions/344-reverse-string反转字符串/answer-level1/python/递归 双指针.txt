### 解题思路
递归方法 两个指针往中间移动并交换元素直到相遇

### 代码

```python
class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        def digui(left,right):
            if left<right:
                s[left], s[right] = s[right], s[left]
                digui(left+1,right-1)
        
        digui(0,len(s)-1)

```