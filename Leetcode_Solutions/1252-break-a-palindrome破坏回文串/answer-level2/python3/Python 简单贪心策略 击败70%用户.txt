![image.png](https://pic.leetcode-cn.com/36aec06a3c1b3ccb50201c6e061d9351dae9a5257de3ef655b8b3dfa44d044a8-image.png)


```
'''
贪心策略
只看左边一半字符，找第一个不是a的字符，将其变成a, 字典序就是最小的
找不到这样的字符，把原来字符串最后一个字符变成b

'''

class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        if n <= 1:
            return ''

        last_idx = n // 2 - 1
        for i in range(0, last_idx + 1):
            if palindrome[i] != 'a':
                return ''.join([palindrome[j] if j != i else 'a' for j in range(n)])

        return palindrome[:-1] + 'b'
```
