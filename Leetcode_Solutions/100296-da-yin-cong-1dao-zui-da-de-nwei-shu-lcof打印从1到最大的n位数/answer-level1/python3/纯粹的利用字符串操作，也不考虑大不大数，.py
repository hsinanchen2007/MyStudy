```
class Solution:
    def printNumbers(self, n: int) -> List[int]:
'''类似于笛卡尔积的感觉，最后去掉头部0'''
        a=[[str(i) for i in range(0,10)]]*n
        b=['']
        for i in a:
            b=[z+h for z in b for h in i]
        return [int(i) for i in b ][1:]
```
