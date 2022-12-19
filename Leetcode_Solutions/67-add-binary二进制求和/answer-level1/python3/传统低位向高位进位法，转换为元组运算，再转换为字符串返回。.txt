### 解题思路
![image.png](https://pic.leetcode-cn.com/e9977363d68a679d00fd76817dce56af13f6d91410dd38be7e32dac69906c13f-image.png)
此处撰写解题思路
1.较短字符串补零
2.从低位向高位遍历，按位相加
3.判断最高位是否有进位。
4.若有则在最高位补一
5.转为字符串，返回结果
### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n = max(len(a), len(b))
        a = a.zfill(n)
        a = list(a)
        b = b.zfill(n)

        flag = 0
        for i in range(n-1, -1, -1):
            value = flag + int(a[i]) + int(b[i])
            if value == 0:
                a[i] = '0'
            elif value == 1:
                a[i] = '1'
                flag = 0
            elif value == 2:
                a[i] = '0'
                flag = 1
            elif value == 3:
                a[i] = '1'

        a = "".join(list(a))
        if flag == 1:
            a = a.rjust(n+1, '1')
        return a

```