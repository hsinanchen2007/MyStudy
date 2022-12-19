### 解题思路
《九章算术》中记录的开方方法，读书的时候我爸爸教我的，虽然考试的时候基本用不到，但今天看到这道题刚好就想起来了
计算过程：
1.开方时我们应先将开放数从个位开始每两个数做一个隔开标记，根据数的大小分成不同的几段，注意区分几段的位数。
2.先求最高位上的数的平方根结果，记住是最高位不是最低位数。
3.把之前隔好的第一段数减去数字最高位平方数，结果旁边要写上隔开第二段数变成一个余数。
4.先用二乘以最高位减去我们刚刚组成的余数，所得数即为试商。
5.再用二乘以商的最高位添加试商再乘以他，结果小于等于余数，那么结果就是平方根的二位数，如果大于余数，那就重新调整试商的数值。
执行用时32ms 也还马马虎虎吧
### 代码

```python3
def withInTwoDigits(x): # 求两位数以内的平方根 例如  82的平方根是9
    squareList = [[1,1],[4,2],[9,3],[16,4],[25,5],[36,6],[49,7],[64,8],[81,9]]
    result = 0
    if x > 81:
        result = 9
    elif x <= 81: 
        for i in range(9):
            if squareList[i][0] == x :
                result = squareList[i][1]
                break
            elif squareList[i][0] < x and x < squareList[i+1][0]:
                result = squareList[i][1]
                break
    return result
class Solution:
    def mySqrt(self, x: int) -> int:
        string = str(x)
        lenth = len(string)
        if lenth <= 2: # 两位数以内开方
            result = withInTwoDigits(x)
        else: # 三位数以上开方
            resultStr = ""
            # 右边第一组的处理
            if lenth % 2 == 1:
                quotient = withInTwoDigits(int(string[0])) # 1
                resultStr = resultStr + str(quotient) # "1"
                remainder = int(string[0]) - pow(quotient,2)
                start = 1
            elif lenth % 2 == 0:
                quotient = withInTwoDigits(int(string[0]) * 10 + int(string[1])) 
                resultStr = resultStr + str(quotient) # "1"
                remainder = int(string[0]) * 10 + int(string[1]) - pow(quotient,2)
                start = 2
            #  第二组及以后的处理
            for i in range(start,lenth,2):
                divedend = remainder * 100 + int(string[i]) * 10 + int(string[i+1]) # 被除数 3
                divisorTry = int(resultStr) * 20 # 试除  4
                quotientTry = divedend//divisorTry
                remainder = divedend - (int(resultStr) * 20 + quotientTry) * quotientTry
                while remainder < 0:
                    if (int(resultStr) * 20 + quotientTry) * quotientTry > divedend :
                        quotientTry = quotientTry - 1
                    remainder = divedend - (int(resultStr) * 20 + quotientTry) * quotientTry
                resultStr = resultStr + str(quotientTry)
            result = int(resultStr)
        return result
```