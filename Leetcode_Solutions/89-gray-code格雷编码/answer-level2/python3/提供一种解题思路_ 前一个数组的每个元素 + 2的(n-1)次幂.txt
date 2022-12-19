```
class Solution:
    '''
    格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
    给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
    输入: 2
    输出: [0,1,3,2]
    解释: 00 - 0, 01 - 1, 11 - 3, 10 - 2
    '''

    def grayCode(self, n: int):
        # 观察连续数值对应的格雷编码序列对应的关系
        # 追加二进制位到首位, 0: 数值仍为前一个数组的值, 1: 前一个数组的每个元素 + 2的(n-1)次幂
        ans, cnt = [0], 0
        while cnt < n:
            ad = 2**cnt
            tmp = list(map(lambda x: x ^ ad, ans))
            tmp.reverse()
            ans += tmp
            cnt += 1
        return ans
```