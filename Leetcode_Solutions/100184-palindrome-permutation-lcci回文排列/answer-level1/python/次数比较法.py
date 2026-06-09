![捕获.PNG](https://pic.leetcode-cn.com/b9286fdaa07700b7242d0917e5bf91859abac0bc77c29399bd1e6eb4c7ba88f8-%E6%8D%95%E8%8E%B7.PNG)
```
解题思路：先使用计数器得到字符串s中每个字符的出现的次数，奇数次的出现次数必须为1或0才能构成回文数
from collections import Counter
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        # 计数器，统计s中每一个字符出现的次数
        counter = Counter(s)
        flag = 0
        for key in counter:
            if counter[key] % 2 == 1:
                flag += 1

        if flag == 0 or flag == 1:
            return True
        else:
            return False
```
