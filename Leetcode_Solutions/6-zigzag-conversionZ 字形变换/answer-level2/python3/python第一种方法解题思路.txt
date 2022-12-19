### 解题思路
执行代码失败，直接提交反而成功了，用pycharm跑自己的测试用例也能成功。很奇怪

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n=len(s)
        row=[""]*numRows
        print(row)
        down=False
        i=0
        if(numRows==1):return s
        if(n==0):return ""
        for c in s:
            if(i==0 or i==numRows-1):down=not down
            #print(c)
            #print(i)
            row[i]+=c
            if down:
                i+=1
            else:
                i+=-1
        #print(row)
        return "".join(row)

```