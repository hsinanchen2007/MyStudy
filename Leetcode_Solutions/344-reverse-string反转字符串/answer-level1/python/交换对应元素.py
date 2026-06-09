### 解题思路
此处撰写解题思路
[0]<->[n-1]
[1]<->[n-2]
交换下就可以。
执行用时 :52 ms, 在所有 Python3 提交中击败了89.43%的用户
内存消耗 :14.5 MB, 在所有 Python3 提交中击败了100.00%的用户
### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        len_s = len(s)
        if len_s < 2:
            return s
        for index,value in enumerate(s):
            if index < len_s/2 :
                tmp = value
                s[index] = s[len_s-1-index]
                s[len_s-1-index] = tmp
        return s
```