### 解题思路
统计各字母出现次数
若字母出现次数都为偶数，则直接返回总次数之和
若有出现次数为奇数的字母，则返回(总数-奇数个数+1)
PS:回文串中间可为出现次数为奇数的字母，故上面+1

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        strList = list(s)
        from collections import Counter
        counter = Counter(strList)
        counter = list(counter.values())
        flag = 0
        tmp = 0
        for i in counter:
            if i % 2 == 1:
                flag = 1
                tmp += 1
        if flag == 0:
            return sum(counter)
        return sum(counter)-tmp+1


```