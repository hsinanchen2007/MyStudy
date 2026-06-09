本题可能意在手动实现进位运算，可是我就不想遂它的意，我命由我！
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        from functools import reduce
        ## 数字转字符串，字符串拼接，拼接后识别成数字，加一，再转为字符串，再拆分
        return list(str(eval(reduce(lambda x,y:x+y,map(str,digits)))+1)) 
```
执行用时战胜 98.15 % 的 python3 提交记录!