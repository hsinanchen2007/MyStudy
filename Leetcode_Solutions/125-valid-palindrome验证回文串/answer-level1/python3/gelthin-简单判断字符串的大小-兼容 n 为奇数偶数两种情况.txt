### 解题思路
首先进行预处理，发现 python3 也可以用 'a'<= x >= 'z' 等来判断
然后从中间用双指针快速判断是否为回文串。
注意到令 i, j = int((n-1)/2), int(n/2) 
则可以兼容 n 为奇数偶数两种情况。


### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        res = ""
        for x in s:
            if 'a' <= x <= 'z':
                res += x
            elif 'A' <= x <= 'Z':
                res += x.lower()
            elif '0' <= x <= '9':
                res += x
        n = len(res)
        i, j = int((n-1)/2), int(n/2)
        flag = True
        while (i>=0) & (j<=n-1):
            if res[i] != res[j]:
                flag = False
                break
            i -= 1
            j += 1
        return flag

```