### 解题思路

用一个数组来进行简单计数。
但要注意小写字母和大写字母要分开计数。



### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        a_hash = [0]*26
        A_hash = [0]*26
        for x in s:
            if ord('a') <= ord(x) <= ord('z'):
                a_hash[ord(x)- ord('a')] += 1
            else:
                A_hash[ord(x)- ord('A')] += 1

        result = 0
        tmp = 0
        for x in a_hash:   # 当仅有一个字符，长为 1 也对
            if x%2 == 0:
                result += x
            else: 
                result += (x-1)
                tmp = 1
        for x in A_hash:
            if x%2 == 0:
                result += x
            else: 
                result += (x-1)
                tmp = 1
        result += tmp

        return result
```