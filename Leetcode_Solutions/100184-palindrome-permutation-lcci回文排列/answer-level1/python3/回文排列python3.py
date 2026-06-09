### 解题思路
**回文串**其实就是**对称字符串**，**对称字符串**中，出现次数为**偶数次**的字符肯定可以对称排列，只需要考虑出现次数为**奇数次**的字符，若出现次数为**奇数次**的字符个数超过 1，则必定不是**对称字符串**。总体思路是先将字符串去重，通过遍历计算每个字符重复的个数，重复个数为**奇数**的字符不能超过 1 个，超过 1 个返回 False 。

### 代码

```python3
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        single_count = 0 # 标记出现次数为奇数的字符总个数
        for c in iter(set(s)): # set函数用于字符串去重
            repeated = 0 # 标记重复个数
            for m in iter(s): # 利用迭代器遍历字符串
                if c == m:
                    repeated += 1
            if repeated % 2 != 0: # 字符出现次数为奇数
                single_count += 1
        if single_count > 1:
            return False
        return True
```