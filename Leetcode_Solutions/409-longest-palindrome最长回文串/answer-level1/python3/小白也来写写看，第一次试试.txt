想法很简单，把字符串转化为字典，每个元素一个键值，挑出奇数和偶数的，只要出现一次奇数，就是回文的最中间一个，偶数的值直接加起来就行

```
class Solution:
    def longestPalindrome(self, s: str) -> int:

        # 先创建一个字典
        count = {}
        for each in s:
            count.setdefault(each, 0)
            count[each] += 1

        num = 0
        i = 0

        # 把字典的值都除以2，num是整除2后的值，累加起来，可以看作是整个回文的一半
        # i的值代表只要只要出现过一次奇数，他就大于1，后面算总个数的时候就要加上回文最中间的一个字符
        for v in count.values():
            num += v // 2
            i += v % 2

        # 上面除以2了，这里要乘回来
        if i > 0:
            return num * 2 + 1
        else:
            return num * 2
```
