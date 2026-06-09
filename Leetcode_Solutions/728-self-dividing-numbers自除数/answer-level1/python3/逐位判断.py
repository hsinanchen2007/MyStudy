```
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res=[]
        for i in range(left,right+1):
            target=i
            while target%10 and not i%(target%10):  #数字里面存在0，是不符合自除数要求的
                target//=10
            if not target:  #判断是除不尽了，还是检查完毕了
                res.append(i)
        return res

```
