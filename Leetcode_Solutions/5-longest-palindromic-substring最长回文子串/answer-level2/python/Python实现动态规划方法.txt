### 解题思路
使用动态规划的方法来解决，思想很简单，这里直接给出递推公式data[i][j] = data[i + 1][j - 1] if s[i] == s[j] else 0，实现上发现边界是由i == j以及j == i + 1组成，并且观察递推公式可以发现表中每个元素的值由它左下方的元素得到，所以我们按照对角线方向从对角线向右上元素填写（只有上三角有意义）；在查找答案时，为了减小数组的遍历次数，按照填写数组的方法的反方向查找，这样能够保证首先查找有没有length长度的回文子串，然后是length-1长度....，查找到的第一个答案即是一个答案。
拓展：如果需要返回同长度的所有答案，只需要把一个斜线上所有的1对应的子串输出即可。

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        data = [[0] * length for _ in range(length)] # 首先要注意的是只有上三角矩阵有用
        
        # 填表，一个斜线一个斜线的填，这种填写方法由递推公式决定
        for offset in range(length):
            for i in range(0, length - offset):
                j = i + offset
                if j - i <= 1:
                    data[i][j] = 1 if s[i] == s[j] else 0
                else:
                    data[i][j] = data[i + 1][j - 1] if s[i] == s[j] else 0
        
        # 查找最长的子串，从右上角出发，同样按照斜线的方式查找，同一斜线上的长度相同
        for offset in range(1, length + 1):
            for i in range(0, offset):
                j = i + (length - offset)
                if data[i][j]:
                    return s[i:j + 1]

        return ''
```