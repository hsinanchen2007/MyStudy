![76b8dd3481bc9e632435534394980b9.png](https://pic.leetcode-cn.com/844d0a24bf29b6b04f28ebc890f7d3451d16253a882d58dbed848318b8d28cd1-76b8dd3481bc9e632435534394980b9.png)

一 算法思想
按索引下标顺序访问数组，若当前数字为0，则为0比特字符，索引加1；反之，若当前数字为1，则为2比特字符，索引加2。
当索引达到最后两位时，若越过倒数第二位直接进入最后一位或进入倒数第二位但倒数第二位为0，则为True;反之为False。
二 算法实现
```
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits)
        i = 0
        while i < n - 2:
            if bits[i] == 1:
                i += 2
            else:
                i += 1
        
        if i == n-2 and bits[-2] == 1:
            return False
        else:
            return True
```
三 复杂度分析
时间复杂度：O(N)。
空间复杂度：O(1)。