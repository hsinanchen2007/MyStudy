### 解题思路
*读错题意，认为严格按题目中解释的样子进行文字图形格式输出，利用字典里面嵌套数组的模式，写出了执行用时和内存最多的算法。。。山路十八弯啊。。*

### 代码

```python3
class Solution:
    def convertx(self,s:str,numRows:int,dictstr :dict,i:int,each):
            if 0 <= i < numRows:
                a = i % numRows
                dictstr[a].append(s[each])
            if numRows <= i < 2*(numRows-1):
                a = (2 * (numRows -1) -i) % numRows
                for c in range(a):
                    dictstr[c].append(" ")
                dictstr[a].append(s[each])
                for c in range(a+1,numRows):
                    dictstr[c].append(" ")
            
    def convert(self, s: str, numRows: int) -> str:
        dictstr = dict.fromkeys(range(numRows))
        t = ""
        if numRows == 1:
            return s
        else:
            for each in range(numRows):
                dictstr[each] = []
            each = 0
            while each < len(s):
                i = each
                if i < 2*(numRows -1):
                    self.convertx(s,numRows,dictstr,i,each)
                    each += 1
                else:
                    i = i % (2*(numRows -1))
                    self.convertx(s,numRows,dictstr,i,each)
                    each += 1
            for each in range(numRows):
                while " " in dictstr[each]:
                    dictstr[each].remove(" ")
                for i in dictstr[each]:
                    t += i
            return t
    '''     for each in range(numRows):
                print(dictstr[each])'''
        

        




```