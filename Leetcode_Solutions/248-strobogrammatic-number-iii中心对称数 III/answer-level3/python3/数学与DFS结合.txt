只列举low、high长度的情况，其他长度直接计算；
直接调用了"中心对称数II"的方法
```
class Solution:
    def strobogrammaticInRange(self, low, high):
        ans = 0
        low_scale, high_scale = len(low), len(high)
        low, high = int(low), int(high)
        if low > high:
            return 0

        for i in range(low_scale + 1, high_scale):
            ans += self._count(i)

        for x in self.findStrobogrammatic(low_scale):
            if low <= int(x) <= high:
                ans += 1
        if high_scale != low_scale:
            for x in self.findStrobogrammatic(high_scale):
                if int(x) <= high:
                    ans += 1
        return ans

    def _count(self, n):
        """ count the nums with n-length """
        if n == 1:
            return 3
        c5, c3 = max(0, n // 2 - 1), n % 2
        return 4 * pow(5, c5) * pow(3, c3)

    def findStrobogrammatic(self, n, start=True):
        if n == 0:
            return []
        if n == 1:
            return ['0', '1', '8']
        if n == 2:
            if start:
                return ['11', '69', '88', '96']
            else:
                return ['00', '11', '69', '88', '96']

        ans = []
        inner_strs = self.findStrobogrammatic(n - 2, False)
        for k in inner_strs:
            if not start:
                ans.append('0' + k + '0')
            ans.append('1' + k + '1')
            ans.append('8' + k + '8')
            ans.append('6' + k + '9')
            ans.append('9' + k + '6')
        return ans
```
