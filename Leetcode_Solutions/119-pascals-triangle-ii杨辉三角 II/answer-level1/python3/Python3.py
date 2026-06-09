执行用时 :48 ms, 在所有 Python3 提交中击败了91.33% 的用户。
内存消耗 :12.8 MB, 在所有 Python3 提交中击败了99.01%的用户。

和上一题一样
```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]
        for i in range(rowIndex):
            tmp = [val for val in res]  #这里不能直接赋值，否则两个变量会指向同一个内存，求解出错
            res += [1]
            for j in range(1, (i+3)//2):
                res[j] = tmp[j-1] + tmp[j]
                res[i+1-j] = res[j]
        return res
```