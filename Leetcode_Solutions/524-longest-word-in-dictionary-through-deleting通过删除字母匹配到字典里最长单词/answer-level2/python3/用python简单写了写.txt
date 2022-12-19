### 解题思路
先匹配字符串，符合子集条件的返回True
随便瞎写写
![image.png](https://pic.leetcode-cn.com/28e69c4906e06e093fb0951ce2978c29a51405d2bc0d1ec26a86ff0e983f08cf-image.png)

### 代码

```python3
from typing import List


class Solution:

    def isSubsequence(self, x: str,  # x是字典的元素
                      y: str) -> bool:  # y是字符串
        i = 0
        for j in range(len(y)):
            if y[j] == x[i]:
                i = i + 1
                if i == len(x):
                    return True

    def findLongestWord(self, s: str,
                        d: List[str]) -> str:
        d.sort(key=lambda x: [-len(x), x])  # 按大到小和字典序排列
        maxword = ""  # 初始化最大匹配
        for word in d:
            if self.isSubsequence(word, s):
                if len(word) > len(maxword):  # 因为前面已经对list进行了排序
                    maxword = word  # 这里只需要找更大的匹配就行
                    # 相等的情况就按前面的字典序优先排好了

        return maxword
```