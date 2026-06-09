![image.png](https://pic.leetcode-cn.com/3aaf57476334be09da3276ecc2b159f07e3265db9494cc0ac836bbfe169766e9-image.png)


```
'''
利用KMP算法求解

ababdef 这样的字符串如果左边全部镜像补全的话
fedbabaababdef一定是一个回文，但是交错的部分会有重复的，并不是最优的：
s:          ababdef
rev:    fedbaba

其实如果能够在s中找到最长的前缀，让前缀等于rev的后缀，那就等于找到了答案
这个问题其实就是求 s + rev 这个序列的kmp next数组中 next[len(s)*2] 的数值
但是要求匹配部分长度不能超过s的长度，所以s 和 rev中间加一个特殊字符即可，
这样可以保证匹配部分不会超过s的长度，

'''


'''
获取KMP next数组
'''
from typing import List
def getKmpNext(data) -> List[int]:
    next = [0 for _ in range(len(data))]
    next[0] = -1
    j, k = 0, -1

    while j < len(data)-1:
        if k == -1 or data[j] == data[k]:
            j, k = j+1, k+1
            next[j] = k
        else:
            k = next[k]

    return next


class Solution:
    def shortestPalindrome(self, s: str) -> str:
        ss = s + "@" + s[::-1] + '#'
        match_len = getKmpNext(ss)[-1]

        return s[match_len:][::-1] + s

print(Solution().shortestPalindrome('aacecaaa'))
```
