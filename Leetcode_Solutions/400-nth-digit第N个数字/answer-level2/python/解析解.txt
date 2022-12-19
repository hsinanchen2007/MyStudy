有明显的解析解，不推荐暴力求解（目测性能不达标）。
求解思路：
1> 确定结果所在的数字位数
2> 确定结果所在的数字及在该数中的索引
3> 将该数转为数组求得索引对应的数字值
```
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        k = 0
        count = 0

        while count < n:
            k += 1
            count += 9 * 10**(k - 1) * k
        clip_num = n - count + 9 * 10**(k - 1) * k

        k_num = (clip_num - 1) / k
        k_end = (clip_num - 1) % k
        num = 10**(k - 1) + k_num

        return int(str(num)[k_end])
```
