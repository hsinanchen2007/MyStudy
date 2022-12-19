思路来源于官方题解：
https://leetcode-cn.com/problems/ambiguous-coordinates/solution/mo-hu-zuo-biao-by-leetcode/
**枚举：**
我们首先把这个二维坐标分成两部分，前一部分表示 x 坐标，后一部分表示 y 坐标。
例如当给出的二维坐标为 (1234) 时，我们可以把它分成 1, 234，12, 34 和 123, 4 三种情况。
随后对于每一部分，我们再考虑是否可以添加小数点以及在哪里添加小数点。
例如，对于 123，合法的坐标有 1.23，12.3 和 123。
在处理每一部分时，我们需要将出现多余 0 的不合法的坐标去除。
如果我们不添加小数点，那么这个坐标不能有前导 0；
如果我们在某个位置添加小数点，那么整数部分不能有前导 0，小数部分的末尾也不能有 0。

**完整代码**
```
class Solution(object):
    def ambiguousCoordinates(self, S):
        """
        :type S: str
        :rtype: List[str]
        """

        res = []

        S = S[1:-1]  # 去掉首位的()
        for i in range(1, len(S)):  # 分割2部分
            s1 = S[:i]
            s2 = S[i:]

            # 左边放小数点形成的组合
            lefts = []
            if self.isEffictive(s1, flag=1):  # 如1, 23
                # 整数有效, 则添加
                lefts.append(s1)
            # 在左边放小数点
            for j in range(1, len(s1)):  # 分割2部分
                s11 = s1[:j]
                s12 = s1[j:]
                if self.isEffictive(s11, flag=1) and \
                        self.isEffictive(s12, flag=2):
                    # 整数及小数部分均有效，则添加
                    tmp = s11 + "." + s12
                    lefts.append(tmp)

            # 右边放小数点形成的组合
            rights = []
            if self.isEffictive(s2, flag=1):  # 如1, 23
                # 整数有效, 则添加
                rights.append(s2)
            # 在右边放小数点
            for j in range(1, len(s2)):  # 分割2部分
                s21 = s2[:j]
                s22 = s2[j:]
                if self.isEffictive(s21, flag=1) and \
                        self.isEffictive(s22, flag=2):
                    # 整数及小数部分均有效，则添加
                    tmp = s21 + "." + s22
                    rights.append(tmp)

            # 左边组合任取一个，右边组合任取一个
            for left in lefts:
                for right in rights:
                    tmp = "(" + left + ", " + right + ")"
                    res.append(tmp)

        return res

    def isEffictive(self, nums, flag):
        """
        :param nums:
        :param flag: flag=1, 整数部分，flag=2 小数部分
        :return:
        """
        """
        整数开头不能为0
        小数末尾不能为0
        """
        if flag == 1:
            if len(nums) > 1:
                return nums[0] != "0"
            return True
        if flag == 2:
            return nums[-1] != "0"
```


