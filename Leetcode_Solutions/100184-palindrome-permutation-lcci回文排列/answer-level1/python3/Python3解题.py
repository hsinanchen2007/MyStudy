### 解题思路
最多只能有一个字符的个数是奇数，剩下的必须全为偶数

### 代码

```python
from collections import Counter
class Solution(object):
    def canPermutePalindrome(self, s):
        """最多只能有一个字符的个数是奇数，剩下的必须全为偶数
        :type s: str
        :rtype: bool
        """
        # 字符计数
        counter_s = Counter(list(s))

        # 统计其中奇数个数
        odd_count = 0
        for k, v in counter_s.items():
            if v%2 == 1:
                odd_count += 1

        # 奇数个数只能为1个或0个，对应abcba（c可以为1、3、5...等奇数个）、abba这种情况
        if odd_count>1:
            return False
        else:
            return True


if __name__ == '__main__':
    s = 'tactcoa'
    solution = Solution()
    print(solution.canPermutePalindrome(s))
```