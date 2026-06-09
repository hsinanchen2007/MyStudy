```python
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if len(matrix) == 0:
            return []
        
        rn = len(matrix)  # 行数
        cn = len(matrix[0])  # 列数
        r, c = 0, 0  # 起始坐标
        rlist = []  # 返回数组
        
        # 每旋转一次后，行数和列数都减2，减了以后如果都还大于0，则说明旋转还未完成
        while rn > 0 and cn > 0:
            # 首先将起始元素取了，不参与后面的循环
            rlist.append(matrix[r][c])
            
            # 从左往右取第一行
            for i in range(cn - 1):
                c = c + 1
                rlist.append(matrix[r][c])
            
            # 从上往下取最后一列
            for i in range(rn -1):
                r = r + 1
                rlist.append(matrix[r][c])
                
            # 如果剩余行数大于1，才进行从右往左取，避免只剩1行的情况下和上面的从左往右操作取到重复元素
            if rn > 1:
                # 从右往左取最后一行
                for i in range(cn - 1):
                    c = c - 1
                    rlist.append(matrix[r][c])
            
            # 如果剩余列数大于1，才进行从下往上取，避免只剩1列的情况下和上面的从上往下操作取到重复元素
            if cn > 1:
                # 从下往上取第一列，除去起始元素
                for i in range(rn - 2):
                    r = r - 1
                    rlist.append(matrix[r][c])
                
            # 修改起始坐标，一边进行下一次循环
            c = c + 1
            
            # 每旋转一次，行数和列数都减少2个
            rn = rn - 2
            cn = cn - 2
            
        return rlist

```