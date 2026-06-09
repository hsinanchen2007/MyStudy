### 解题思路
用数组表示一个大数，一位位的填充，使用递归思想

### 代码

```python3
class Solution:
    def __init__(self):
        self.res=[]
    def printNumbers(self, n: int) -> List[int]:
        if n<=0:
            return []
        number=["0"]*n#初始化一个n的数组，来表示n位数字，
        number[-1]="0"#初始化
        for i in range (0,10):
            number[0]=chr(ord("0")+i)
            #ord 与chr 是配对函数，ord将相应的字符串转换为ASCII码，char是将ASCII码转换为字符串
            self.print1ToMaxOfN(number,n,0)
        return self.res[1:]
    def print1ToMaxOfN(self,number,length,index):
        if index==length-1:
            self.printHelper(number)
            #数组转化为字符串
            self.res.append(int("".join(number)))
            return 
        else:
            for i in range (0,10):
                number[index+1]=chr(ord("0")+i)
                self.print1ToMaxOfN(number,length,index+1)
    def printHelper(self,number):
        number=int("".join(number))
        if number!=0:
            print(number)

```