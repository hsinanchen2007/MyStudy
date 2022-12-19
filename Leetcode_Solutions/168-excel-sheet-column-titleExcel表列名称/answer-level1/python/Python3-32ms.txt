### 解题思路

一看题目我首先会想到先建立从1～26映射到'A'~'Z'的字典
然后我本来以为是26进制的问题，可是好像没这么简单
原因是在所给的例子中，701转换为26进制是[1, 0, 25]即：1·26^2 + 0·26^1 + 25·26^0 = 701
但是我并没有定义0映射到什么字母，所以把高位1左移动一位变成了[0, 26, 25]即：0·26^2 + 26·26^1 + 25·26^0 = 701
高位零可舍弃，所以701对应的是[26, 25]，映射到相应字典就是"ZY"


### 代码

```python3
class Solution:
    def convertToTitle(self, n: int) -> str:
        letList = [chr(num) for num in range(65, 91)]
        numList = [*range(1, 27)]
        dic = dict(zip(numList, letList))

        baseList = []
        q, r = divmod(n, 26)
        baseList.append(r)

        while q != 0:
            q, r = divmod(q, 26)
            baseList.append(r)
        baseList[:] = baseList[::-1]

        while 0 in baseList:
            idx0 = baseList.index(0)
            baseList[idx0] = 26
            baseList[idx0-1] -= 1
            if idx0-1 == 0 and baseList[idx0-1] == 0:#若高位有0，舍弃该位
                baseList.pop(idx0-1)

        s = ''
        for i in baseList:
            s += dic[i]

        return s
```