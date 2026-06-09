### 解题思路
这一题有大量相似题目，相同思路，我做过好几次习题。

[387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

还有一些有待寻找。



### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> str:  #### 肯定又相似题目，我都用了好几次set 了
        n = len(s)
        if n == 0:
            return " "
        if n == 1:
            return s[0]
        A = dict()
        for x in s:  ## 这一段代码也写了好多次， 只用一个 hash set
            if x not in A:
                A[x] = 1
            else:
                A[x] += 1
        for x in s:
            if A[x] == 1:
                return x
        return " "
```