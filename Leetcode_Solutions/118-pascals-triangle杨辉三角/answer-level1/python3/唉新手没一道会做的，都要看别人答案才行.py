```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        l = []
        for n in range(numRows):
            if n < 2:
                n_row = [1 for i in range(n + 1)]    //前两行都是1
            else:
                last_row = l[-1]    //上一行
                row_mid = [last_row[i] + last_row[i + 1] for i in range(n - 1)]     //中间的几个值
                n_row = [1] + row_mid + [1]        //两边是1，拼上中间的
            l.append(n_row)
        return l
```
