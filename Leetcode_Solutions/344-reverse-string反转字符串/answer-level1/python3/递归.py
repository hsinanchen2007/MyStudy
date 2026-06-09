### 解题思路
递归
注释是自己想到的递归方式，将第一个扔最后一个，第二个扔倒数第二个，测试用例找了个超复杂的用例，内存溢出了。
看了官方给的解题思路，算是两两替换吧， 第一个和最后一个替换，第二个和倒数第二个替换。这样空间复杂度是不是
从O(N)减小到O(1)?
### 代码
```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # def func(sh):
        #     if len(sh) < 1:
        #         return sh
        #     return func(sh[1:])+list(sh[0])
        # s[:]=func(s)
        def helper(left, right):
            if left < right:
                s[left], s[right] = s[right], s[left]
                helper(left + 1, right - 1)
        helper(0, len(s) - 1)
```