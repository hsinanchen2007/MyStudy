### 解题思路
此处撰写解题思路
重点考虑 某一位数字为1 0 的情况 以及1 0 出现在最高位的情况就行
### 代码

```python
class Solution(object):
    def getNoZeroIntegers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        num = [int(c) for c in str(n)]
        num.reverse()
        result = [[],[]]
        decFlag = False
        for i in range(len(num)):
            if decFlag:
                if num[i] == 0:
                    num[i] = 9
                    decFlag = True
                else:
                    num[i] -= 1
                    decFlag = False
            if num[i] > 1:
                result[0].append(1)
                result[1].append(num[i] - 1)
            elif num[i] == 1 and i < len(num) - 1:
                result[0].append(2)
                result[1].append(9)
                decFlag = True
            elif num[i] == 1:
                result[0].append(1)
            elif num[i] == 0 and i < len(num) - 1:
                result[0].append(1)
                result[1].append(9)
                decFlag = True
            #print(result)
        result[0].reverse()
        result[1].reverse()
        intResult = []
        intResult.append(int("".join([str(i) for i in result[0]])))
        intResult.append(int("".join([str(i) for i in result[1]])))
        return intResult
```