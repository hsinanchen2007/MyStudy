### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverse(self, x):
        neg = False     #负数判断参数
        Sx = str(x)     
        if Sx.startswith('-'):  #如果为负
            neg = True
            Sx = Sx[1:]        #从第二个开始遍历，最后在加上负号
        reSx = ''
        SxList = []
        for i in Sx:          #使用stack
            SxList.append(i)
        for k in Sx:          
            reSx = reSx + SxList.pop() 
        #出stack顺序是相反的，生成字面相反string（如原字符0为结尾，新字符0为开头）
        while reSx.startswith('0') and len(reSx)!=1: 
            reSx = reSx.replace('0','',1)    #如果以0开始，替换成空字符，一次替换一个
        if neg: numSx = 0 - eval(reSx)        #如为负数，还原负号
        else: numSx = eval(reSx)
        if numSx > 2**31-1 or numSx < -2**31: numSx = 0  #计算是否超出阈值
        return numSx



```