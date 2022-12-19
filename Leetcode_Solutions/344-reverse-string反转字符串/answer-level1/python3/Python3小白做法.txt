### 解题思路
首先把s中的元素先提取出来到a中，在将a进行字符串反转，把s清空，在一个个的将a中的元素加入到s中去

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        a=""
        for i in s:
            a+=i
        a=a[::-1]
        s.clear()
        for i in range(len(a)):
            s.append(a[i])
```