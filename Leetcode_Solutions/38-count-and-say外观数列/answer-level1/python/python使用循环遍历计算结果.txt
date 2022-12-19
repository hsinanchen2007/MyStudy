主要思路：
    1 遍历上一次得到的字符串
    2 在遍历过程中，得到每个数字出现的次数
    3 在每得到一个数字以及该数字出现的次数后，将给当前结果添加内容
    4 添加的内容为 当前数组出现的次数转化为字符 + 当前数字的字符

代码如下

 ```
class Solution(object):
    def countAndSay(self, n):
        if n <= 0:
            return
        oldStr = "1"
        loop = 0

        # 计算后面的loop-1个结果
        while loop < n-1:
            loop += 1
            newStr = ""
            oldLength = len(oldStr)

            # 当前查看的数字以及该数字连续出现的次数
            index = 0
            while index < oldLength:
                number = oldStr[index]
                count = 1
                # 计算该数字连续出现的次数
                while index+1 < oldLength and oldStr[index] == oldStr[index + 1]:
                    index += 1
                    count += 1
                # index指向下一个于该数字不同的数字
                index += 1
                newStr += str(count)+number

            # 跟新结果
            oldStr = newStr
        return oldStr
```
