### 解题思路
此处撰写解题思路
1.建立元组c，最长为max（lena，lenb）+ 1
2.从低位向高位遍历，直到a或b遍历完，进位用flag = 1表示，value = 0，1，2，3表示不用的当前位的结果和高位的进位情况
3.b遍历完后，计算a+flag
4.a也遍历完后，注意flag==1时，c[0]=1,并返回c。否则c[0]=0，直接返回c[1:]

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        lena, lenb = len(a), len(b)
        c = '0'
        if lena >= lenb:
            c = ['0' for i in range(lena+1)]
        else:
            c = ['0' for i in range(lenb+1)]

        i, j, k = lena - 1, lenb - 1, len(c) - 1
        flag = 0

        while i >= 0 and j >= 0:
            value = int(a[i]) + int(b[j]) + flag
            if value == 0:
                c[k] = '0'
            elif value == 1:
                c[k] = '1'
                flag = 0
            elif value == 2:
                c[k] = '0'
                flag = 1
            else:
                c[k] = '1'
                flag = 1
            i -= 1
            j -= 1
            k -= 1

        if i == -1:
            while flag != 0 and j >= 0:
                value = int(b[j]) + flag
                if value == 2:
                    c[k] = '0'
                    flag = 1
                elif value == 1:
                    c[k] = '1'
                    flag = 0
                k -= 1
                j -= 1
            while j >= 0:
                c[k] = b[j]
                k -= 1
                j -= 1

        if j == -1:
            while flag != 0 and i >= 0:
                value = int(a[i]) + flag
                if value == 2:
                    c[k] = '0'
                    flag = 1
                elif value == 1:
                    c[k] = '1'
                    flag = 0
                k -= 1
                i -= 1
            while i >= 0:
                c[k] = a[i]
                k -= 1
                i -= 1
        if flag == 1:
            c[0] = '1'
            return "".join(c)
        if flag == 0:
            return "".join(c[1:])


```