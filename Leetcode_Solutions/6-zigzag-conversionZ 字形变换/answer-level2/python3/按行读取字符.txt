


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        # 输出的字符串
        outstr = ""
        # 如果不设置1的话, 若numRows为1, 会陷入死循环
        if numRows == 1:
            step = 1
        else:
            step = (numRows - 1) * 2

        for i in range(numRows):
            # 用于标记的一行的个数
            j = 0
            # 用于检验是否超出s的长度
            length = i
            while length < len(s):
                outstr += s[length]
                if i == 0 or i == numRows-1:
                    # 头行和尾行, 只需要一个step
                    length += step
                else:
                    # 中间的行一个step中会有2个值(一般情况下)
                    length += abs(step * ((j + 1)%2) - i * 2) 
                    j += 1
        
        return outstr