### 解题思路
[这篇文章讲的很清晰](https://mp.weixin.qq.com/s?__biz=MzI1MTIzMzI2MA==&mid=2650565284&idx=1&sn=33f7d3dc982b2b550f30a24479a9fe4f&chksm=f1fedc27c689553167f471b3b4d080bcb13bf60825d73262f55f2bbe2639835ff71ab4b78f33&scene=90&xtrack=1&subscene=93&clicktime=1585270305&enterid=1585270305&ascene=56&devicetype=android-29&version=27000c37&nettype=cmnet&abtest_cookie=AAACAA%3D%3D&lang=zh_CN&exportkey=AcMkX3Wz2R%2FbrFQhhHTXb1E%3D&pass_ticket=Yev4uphdlQgWK%2B8IcjrcCL9Tc5RuWPlpGIedumB0PPv1SOaSyBC1NcIuf%2FByxb%2Bk&wx_header=1)

我这里就不班门弄斧了

### 代码

```python
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.res = []
        # 存放每一行的皇后存放的位置
        self.ans = [-1] * n
        # 求log2(N)
        def lg(n):
            count = 0
            while (n > 0):
                n = n >> 1
                count+=1
            return count
        #拼接结果字符 x 表示皇后所占位
        def getStr(x):
            str = "." * (x - 1)
            str += "Q"
            str += "." * (n - x)
            return str
        # 把求得的结果保存到self.res 的全局变量中
        def add():
            tmp = ["."] * n
            for i in range(n):
                tmp[i] = getStr(self.ans[i])
            self.res.append(tmp)
        # row 当前待求行
        # 这一部分麻烦看上面链接
        def queenSettle(row, column, pie, na):
            if row >= n:
                add()
            # 取出当前行可放置皇后的格子
            bits = (~(column | pie | na)) & ((1 << n) - 1)
            while bits > 0:
               
                #p = bits & -bits
                # 因为负数是用补码表示的，所以这一句可以用上面注释代码替代
                p=bits&(~bits+1)
                self.ans[row] = lg(p)
                queenSettle(row + 1, column | p, (pie | p) << 1, (na | p) >> 1)
                #清空最后一位1
                bits = bits & (bits - 1)

        queenSettle(0, 0, 0, 0)

        return self.res
```