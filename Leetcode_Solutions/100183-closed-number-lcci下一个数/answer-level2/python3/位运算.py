位运算, 具体逻辑有注释
```python
class Solution:
    def findClosedNumbers(self, num: int) -> List[int]:
        mn, mx = 1, 2147483647

        def findLarge(n):
            # 从右开始找到第1个1
            # 然后记录1的个数ones直到再遇到0或到最高位
            # 然后将这个0变成1
            # 然后右边的位数用000...111(ones-1个1)填充
            checkMask = 1
            bits = 0
            while checkMask <= n and checkMask & n == 0:
                checkMask <<= 1
                bits += 1
            ones = 0  # 直接构造出000...111
            while checkMask <= n and checkMask & n != 0:
                ones = (ones << 1) + 1
                checkMask <<= 1
                bits += 1
            # 因为在改变的位已经将1个0转成1了, 所以这里ones要向右移动一位
            ones >>= 1
            # 将0转成1
            n |= checkMask
            # 清除右边的0
            n = (n >> bits) << bits
            # 将右边填充上ones
            n |= ones
            return n if mn <= n <= mx else -1

        def findSmall(n):
            # 从右开始找到第1个0, 记录此过程1的个数ones
            # 然后继续往左找直到再遇到1
            # 然后将这个1变成0, ones也要左移一位(也可以初始化为1)
            # 然后右边的位数用高位ones个1填充, 即构造出111...000, 可以直接基于ones构造
            # 注意如果全为1的话是无解的, 直接返回-1
            checkMask = 1
            bits = 0
            ones = 1
            while checkMask <= n and checkMask & n != 0:
                checkMask <<= 1
                bits += 1
                ones = (ones << 1) + 1
            if checkMask > n:
                # 全部是1
                return -1
            while checkMask <= n and checkMask & n == 0:
                checkMask <<= 1
                bits += 1
                ones <<= 1
            # 因为ones初始化为1, 所以ones需要右移一位
            ones >>= 1
            # 将需要改变的1变成0
            n &= ~checkMask
            # 清除右边的0
            n = (n >> bits) << bits
            # 将右边填充上ones
            n |= ones
            return n if mn <= n <= mx else -1

        return [findLarge(num), findSmall(num)]
```
