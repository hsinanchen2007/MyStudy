循环遍历，每次减去小于i的最大平方数
```
class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0]*(num+1)
        squareNum = 1
        for i in range(1,len(res)):
            if i == squareNum:
                res[i] = 1
                squareNum *= 2
            else: res[i] = res[int(i-squareNum/2)] + 1
        return res
```
