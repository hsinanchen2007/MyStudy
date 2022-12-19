思路：
观察N型图形，发现N型中间斜着的部分是n-2个，而竖着的元素是n个，每次取个V型元素段，然后根据规律找出在每一行的元素，重组新的字符串。

总体来说，最后的z型重组之后的字符串是：z_str = first_line + middle_line + last_line
如果numRows = 1，直接返回s
如果numRows 不是 1：
（1）把字符串s转成list --> lst
（2）我打算把lst按照2n-2的长度分段。最后一段不足2n-2则让lst全部补上''元素。
（3）计算我分的段长length = len(lst)//(2n-2)，定义一个空字符串z_str = ''
（4）每次循环length遍（range(length)），取lst[i*(2n-2)]，也就是某段的第一行
（5）取中间行，去掉第一行和最后一行之后，在range(1, numRows-1)的范围内，每次循环length遍，取出每一段，然后再取出每一段中的第i个和倒数第i个
（6）取最后一行，同取中间行的步骤，取出每一段，然后再去每一段的第numRows-1个元素。



代码：
```
class Solution:
    def convert(self, s, numRows):
        l = 2*numRows-2
        if numRows == 1:
            return s
        last_len = l - (len(s) % l) if len(s) % l else 0
        new_str = list(s)
        for i in range(last_len):
            new_str.append('')
        # 新的字符串已经出来了
        length = len(s) // l if not len(s) % l else len(s) // l + 1
        # z_str
        z_str = ''
        # first_line
        for i in range(length):
            z_str += new_str[i*l]
        # second_line
        for i in range(1, numRows-1):
            for j in range(length):
                z_str = z_str + new_str[j*l:(j+1)*l][i] + new_str[j*l:(j+1)*l][-i]
        # last_line
        for i in range(length):
            z_str += new_str[i*l:(i+1)*l][numRows-1]
        return z_str
```
