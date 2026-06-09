不多bb先上代码
```
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        summ, index, ins = 0, 0, 0
        for i in range(len(light)):
            index += (i + 1)
            summ += light[i]
            if index == summ:
                ins += 1
        return ins
```
思路:
反正要都变蓝
那么最右边的灯的左边所以都得亮着
且给的是1~n的序列
所以嘛   一个记录前i个自然数之和
一个记录里亮着的灯的和
相同就是都蓝
嘻嘻