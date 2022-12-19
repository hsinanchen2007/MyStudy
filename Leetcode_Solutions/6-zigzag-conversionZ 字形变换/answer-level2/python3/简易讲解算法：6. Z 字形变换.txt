解法一：

```
res[0]    0       8         16
res[1]    1     7 9      15 17
res[2]    2   6   10   14   18
res[3]    3 5     11 13     19
res[4]    4       12        20
```

按次序依次，从0-20，放入0到4的res，再4到0，一直到字符串结束，最后拼接res就可以了


```python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows<2:
            return s
        res = ['' for _ in range(numRows)]
        i,flag = 0,1
        for temp in s:
            res[i] += temp
            i+=1*flag
            if i==0 or i==numRows-1:
                flag *= -1
        else:
            return ''.join(res)
```


解法二：

间隔=8
```
0       8         16    i=8  j=0
1  i  7 9  i   15 17    i=6  j=2
2   6   10   14   18    i=4  j=4
3 5  j  11 13  j  19    i=2  j=6
4       12        20    i=0  j=8
```

行数numRows
间隔=i=(numRows-1)*2
j=0
i+j==间隔
每行运行结束，i-2,j+2

```python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        length = len(s)
        if numRows<2:
            return s
        i=first=(numRows-1)*2
        j=0
        temp =''
        count=0
        while j<=first:
            index=count
            while index<length:
                temp=temp+s[index]
                if i!=0 and index+i<length:
                    temp+=s[index+i]
                if j==0:
                    index=index+i*2
                else:
                    index = index+i+j
            count+=1
            i-=2
            j+=2
        return temp
```



