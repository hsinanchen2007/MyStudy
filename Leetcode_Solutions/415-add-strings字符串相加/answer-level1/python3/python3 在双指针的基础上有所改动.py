### 解题思路
1. 先用字符串切片将两个字符串反转
2. 利用一个for循环先将公共字符串的加法计算完
3. 然后再计算剩余的部分
4. add表示是否有进位
5. result返回的字符串
6. 代码比较冗余没优化，效率可能比双指针要高一点
执行用时 :40 ms, 在所有 Python3 提交中击败了91.35%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了29.10%的用户

### 代码

```python3
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if len(num1) < len(num2):
            num1, num2 = num2, num1
        num1 = num1[::-1]
        num2 = num2[::-1]
        add = 0
        result = ''
        for i, j in zip(num1, num2):
            temp = int(i) + int(j) + add
            if temp > 9:
                result += str(temp - 10)
                add = 1
            else:
                result += str(temp)
                add = 0
        if add == 0:
            result += num1[len(result):]
        elif len(result) == len(num1):
            result += '1'
        else:
            for k in range(len(result),len(num1)):
                temp = int(num1[k]) + add
                if temp > 9:
                    result += str(temp - 10)
                    add = 1
                else:
                    result += str(temp)
                    add = 0
                    break
            if add == 0:
                result += num1[len(result):]
            else:
                result += '1'
        return result[::-1]
                
```