思路：
1、先将字符串转为数字求和
2、在列表里面操作进位，其中留下第0位做拼接判断
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        num = int(a) + int(b)  # 先加起来
        string = str(num)
        temp = []
        for s in string:  # 在列表里面操作进位
            temp.append(int(s))
        for i in range(len(temp)-1, 0, -1):  # 留下0位做拼接判断
            if temp[i] == 2:
                temp[i] = 0
                temp[i-1] += 1
            if temp[i] == 3:
                temp[i] = 1
                temp[i-1] += 1
        if temp[0] == 2:
            temp[0] = 0
            temp = [1] + temp
        if temp[0] == 3:
            temp[0] = 1
            temp = [1] + temp
        s = ''
        for num in temp:
            s += str(num)
        return s
```
