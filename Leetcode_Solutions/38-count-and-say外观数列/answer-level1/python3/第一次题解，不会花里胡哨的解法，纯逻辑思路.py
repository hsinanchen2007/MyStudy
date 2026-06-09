```python
class Solution:
    def countAndSay(self, n: int) -> str:
        count = 1
        strList = []
        returnStr = "1"
        for i in range(1, n):
            strList.clear()
            for j in range(0,len(returnStr)):
                if j + 1 < len(returnStr) and returnStr[j] == returnStr[j+1]:
                    count += 1
                else:
                    strList.append(str(count))
                    strList.append(returnStr[j])
                    count = 1
            returnStr = ''.join(strList)
        return returnStr
```
题目已知最小次数为1，所以循环从1开始，遇到1直接返回需要的值。
如果不为1，重点在于寻找连续相等的字符串。
例如 22 -> 22 222 -> 32 
所以遍历的时候提取出连续相等的字符串放入期待结果中就ok

解答代码中两个for循环，第一个对应题目所需要的循环次数，第二个则是遍历前一次结果集。（默认为1）
if的作用就是找连续，else则将当前的连续（最低连续次数为1）的结果放到list中。
再然后把list变成字符串结果集进行下一次循环，直至结束并返回。