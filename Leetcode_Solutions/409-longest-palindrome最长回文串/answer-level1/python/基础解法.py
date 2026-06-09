### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        import collections
        # 统计各字符次数
        count = collections.Counter(s).values()
        flag = 0
        sum = 0 
        for n in count:
            if n%2 == 0:
                sum += n
            elif n%2 != 0 and n>2:
                sum +=  n-1
                flag = 1
            else:
                flag = 1
        if flag == 1:
            sum += 1
        return sum

```