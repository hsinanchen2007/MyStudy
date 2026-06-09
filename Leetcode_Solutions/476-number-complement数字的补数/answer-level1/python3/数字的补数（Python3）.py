####思路
先转化为二进制，然后将0位上的数计算得到十进制的补数
#### 代码
```
class Solution:
    def findComplement(self, num: int) -> int:
        ans = 0
        a = bin(num)[2:]  # 转换为二进制的字符串格式
        for i in range(-1,-len(a)-1,-1):
            if a[i] == '0':
                ans += 2**(-i-1)
        return ans
```
#### 复杂度分析
- 时间复杂度：O(N)，N为二进制的长度，遍历了一遍字符串
- 空间复杂度：O(1)，使用了`a`和`ans`
