1.建立n个列表，n为指定的行数numRows，分别储存相应行的字符串
2.字符一直通过从上往下或从下往上进行迭代，而且，从下标为numRows-1的倍数处换行
3.设定一个godown flag，在换行时取反，down时按行在相应列表中添加相应字符，up时反过来添加
4.之后将列表转化为字符串即可


```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        cache = [[]for i in range(numRows)]   # create numRows empty lists 
        if numRows==1:
            return s
        godown = False                       # set godown flag
        for i,string in enumerate(s):         
            j = i%(numRows-1)                # every numRows element change down or up
            if j == 0:                       
                godown = ~godown
            if godown:
                cache[j].append(string)         
            else:
                cache[numRows - 1 - j].append(string)
        cache = [''.join(cache[i]) for i in range(numRows)]
        return ''.join(cache)

```
