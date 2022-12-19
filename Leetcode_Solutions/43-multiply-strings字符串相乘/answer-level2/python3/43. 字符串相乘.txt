### 解题思路
这道题思路并不难，就是写起来很麻烦，容易出错。这道题考大数，虽然python天生自带大数库，但我们应该自己动手实现，就假想能int转化的字符串必须是小点的整数。下面代码的思路是先每个元素对另一个字符串做乘法，保留中间结果，再累加起来，就输出最后的结果。

### 代码

```python3
def addstring(str1, str2):
    len1 = len(str1)
    len2 = len(str2)
    jinwei = 0
    i = 0
    res = ""
    while i<len1 and i<len2:
        jinwei,yushu=divmod(int(str1[len1-1-i])+int(str2[len2-1-i])+jinwei,10)
        res = str(yushu)+res
        i+=1
    while i<len1:
        jinwei,yushu=divmod(int(str1[len1 - 1 - i])+jinwei,10)
        res = str(yushu)+res
        i+=1
    while i<len2:
        jinwei, yushu = divmod(int(str2[len2 - 1 - i]) + jinwei, 10)
        res = str(yushu) + res
        i += 1
    if jinwei!=0:
        res = str(jinwei)+res
    return res


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        len1 = len(num1)
        len2 = len(num2)
        if (len1==1 and int(num1)==0) or (len2==1 and int(num2)==0):
            return "0"
        # 做乘法
        res1 = []
        for i in range(len1):
            a = int(num1[len1-1-i])
            tmp = ""
            jinwei = 0
            for j in range(len2):
                b = int(num2[len2-1-j])
                jinwei,yushu = divmod(a*b+jinwei,10)
                tmp = str(yushu)+tmp
            if jinwei!=0:
                tmp = str(jinwei)+tmp
            res1.append(tmp+"0"*i)

        # 做加法
        res2 = res1[0]
        for i in range(1,len(res1)):
            res2 = addstring(res2,res1[i])

        return res2
```