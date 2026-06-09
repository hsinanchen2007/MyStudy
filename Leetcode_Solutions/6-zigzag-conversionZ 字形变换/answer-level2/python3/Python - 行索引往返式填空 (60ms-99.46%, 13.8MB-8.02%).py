~~~python
# Try_2: 参考了官方详解-行索引往返式填空
# (60ms-99.46%, 13.8MB-8.02%)
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        row_num = min(numRows, len(s))          # 行数，取字符长度与numRows的最小值
        
        # 当行数小于2时，直接返回s
        if row_num < 2:
            return s
        
        ret_lst = ['']*row_num       # 列表长度为row_num，即每个元素表示每一行输出字符
        dy = 1                        # 1/-1，决定行索引运动方向（即往返）
        row_i = 0                     # 当前行索引
        
        for c in s:
            # 对应行加入字符
            ret_lst[row_i] += c
            # 当前行 + dy
            row_i += dy
            # 更新方向(若当前行位于首行或末尾行，更新运动方向)
            dy = -dy if row_i in [0, row_num-1] else dy
            
        ret = ''.join(ret_lst)
        return ret
~~~


