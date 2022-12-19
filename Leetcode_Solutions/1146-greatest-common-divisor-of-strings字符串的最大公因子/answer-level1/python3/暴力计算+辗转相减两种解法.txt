### 解题思路
- 暴力解答, 直接逐个选取能被整除的子串, 判定扩增后是否与长字符串一致;
- 优化算法: 假设两个字符串满足short==MT, long==NT, M<N, T为目标, 则满足条件: T==gcd(MT, (N-M)T);

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        """
        优化算法: 假设两个字符串满足short==MT, long==NT, M<N, T为目标, 则满足条件: T==gcd(MT, (N-M)T);
        类似于辗转相除, 快速降低解空间,提升效率;
        执行用时 :32 ms, 在所有 Python3 提交中击败了80.71%的用户
        内存消耗 :13.5 MB, 在所有 Python3 提交中击败了7.48%的用户
        :param str1:
        :param str2:
        :return:
        """
        n1 = len(str1)
        n2 = len(str2)
        if n1 == n2 and str1 != str2:
            return ""
        if n1 == n2 and str1 == str2:
            # 直接比较字符串可能效率低一些, 先判定长度更快
            return str1
        
        if n1 < n2:
            if n1 == 1 and str1 * n2 == str2:
                return str1
            return self.gcdOfStrings(str2[:n1], str2[n1:])
        else:
            if n2 == 1 and str2 * n1 == str1:
                return str2
            return self.gcdOfStrings(str1[:n2], str1[n2:])

    def gcdOfStrings2(self, str1: str, str2: str) -> str:
        """
       暴力解答, 直接逐个选取能被整除的子串, 判定扩增后是否与长字符串一致;
       优化1: 反向查找, 先判定长字符串;
       :param str1:
       :param str2:
       :return:
       """
        short, long = str1, str2
        if len(short) > len(long):
            short, long = long, short

        gcd = ""
        len_of_short = len(short)
        len_of_long = len(long)
        for end in range(len_of_short + 1, 0, -1):
            if len_of_short % end:
                continue
            if len_of_long % end:
                continue
            tmp = short[:end]
            if tmp * (len_of_short // end) != short:
                continue
            if tmp * (len_of_long // end) != long:
                continue
            return tmp
        return gcd

    def gcdOfStrings1(self, str1: str, str2: str) -> str:
        """
        暴力解答, 直接逐个选取能被整除的子串, 判定扩增后是否与长字符串一致;
        :param str1:
        :param str2:
        :return:
        """
        short, long = str1, str2
        if len(short) > len(long):
            short, long = long, short

        gcd = ""
        len_of_short = len(short)
        len_of_long = len(long)
        for end in range(1, len_of_short + 1):
            if len_of_short % end:
                continue
            if len_of_long % end:
                continue
            tmp = short[:end]
            if tmp * (len_of_short // end) != short:
                continue
            if tmp * (len_of_long // end) != long:
                continue
            gcd = tmp
        return gcd
```