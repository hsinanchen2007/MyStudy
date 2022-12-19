执行用时 :104 ms, 在所有 Python3 提交中击败了56.63%的用户
内存消耗 :13.5 MB, 在所有 Python3 提交中击败了8.35%的用户
```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        length = len(s)
        if length <= numRows or numRows == 1:
            return s
        group = length // (2 * numRows -2)
        left = length % (2 * numRows -2)
        Outdict = {}
        row = numRows
        for num in range(row):
            Outdict[num] = {}
        rownum = 0
        colnum = 0
        newcolum = 0
        for word in s:
            if newcolum == colnum:
                Outdict[rownum][colnum] = word
                if (rownum+1) % numRows == 0:
                    newcolum = colnum + 1
                    continue
                rownum += 1
            if newcolum != colnum:
                rownum -= 1
                Outdict[rownum][newcolum] = word
                if rownum != 0:
                    newcolum += 1
                    colnum += 1
                else:
                    colnum = newcolum
                    rownum += 1
        Output = ''
        for row in Outdict.keys():
            for col in Outdict[row].keys():
                Output = Output + Outdict[row][col]
        return Output
```
