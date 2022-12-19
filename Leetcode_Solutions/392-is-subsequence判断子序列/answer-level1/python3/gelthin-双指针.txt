### 解题思路
此题应该有很多种方法。
可以使用双指针可以解决。有空应该学一下 KMP 算法用于字符串匹配。
对于后续问题，大家的思路一般是对长字符串 t 进行预处理，提取出 t 中的信息，便于后续处理。

有空参考 题解 [c++判断子序列&&后续挑战](https://leetcode-cn.com/problems/is-subsequence/solution/cpan-duan-zi-xu-lie-hou-xu-tiao-zhan-by-zzzzzz-5/) 以及 [对后续挑战的一些思考--如何快速判断大量字符串](https://leetcode-cn.com/problems/is-subsequence/solution/dui-hou-xu-tiao-zhan-de-yi-xie-si-kao-ru-he-kuai-s/)

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        m, n = len(s), len(t)
        a, b = 0, 0
        while a<m and b<n:
            if s[a] == t[b]:
                a += 1
            b += 1
        if a == m:
            return True
        else:
            return False

```