### 解题思路

主要是递归思路，每次移除一个数，使移除后数最大。然后递归，一直到移除了k个数。
该方法，内存消耗太大，时间也不快。
递归开始前：
1. 去除数字前面的无效0；当数字中只有0时，则返回'0'。
2. 如果k大于字符串长度，则移除所有数，返回'0'。
3. 如果k==0，则表明递归结束，返回num。

递归：
从前往后，找到第一个减小的数，移除掉，继续处理剩下的字符串数字，k=k-1。
例如处理字符串'12543'，第一个减小的是数字5，移除，再继续处理'1243'。直至k==0。

### 代码

```python3
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        index_num = -1
        for i in range(len(num)):
            if int(num[i]):
                index_num = i
                break
        if index_num == -1:
            return '0'
        num = num[index_num:]
        if len(num) <= k:
            return '0'
        if k==0:
            return num
        left = 0
        right = 1
        for i in range(1, len(num)):
            right = i
            if int(num[left]) > int(num[right]):
                break
            left = right
        return Solution().removeKdigits(num[:left] + num[left+1:], k-1)

```