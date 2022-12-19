### 解题思路

![Q(ZARV9_M(V}I1VH3V\]I67S.png](https://pic.leetcode-cn.com/5ecfffd721159b8b0c5410c34cb20dcc73cd410019900677be2a471fe0c78a80-Q\(ZARV9_M\(V%7DI1VH3V%5DI67S.png)

### 代码

```python3
class Solution:
    def addDigits(self, num: int) -> int:
        num=list(str(num))                          #先转成列表形式
        b=[]
        for i in num:                               #遍历各个位（因为已经拆开了）
            b.append(int(i))                        #把str转成int
        num=b
        if len(num)==1:                             #如果长度已经是一位数了，
            num=' '.join('%s' %id for id in num)    #为了去掉列表的那个[]
            return num                              #就直接输出
        else:
            num=[i for index,i in enumerate(num[:])]#否则，把列表中的每一位拿出来，
            num=sum(num)                            #相加
            return self.addDigits(num)              
```