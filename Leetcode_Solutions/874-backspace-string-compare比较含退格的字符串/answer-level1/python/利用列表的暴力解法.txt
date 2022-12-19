### 解题思路
因为字符串属于不可变的数据类型，故转成列表，思想朴素，遇到#就置之前一个字符为空
时间O(N)空间0(N)

### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        slist = [i for i in S]
        tlist = [j for j in T]
        for i in range(len(slist)):
            if slist[i] == '#':
                slist[i]=''
                if i!=0:
                    tmp = i - 1
                    while (slist[tmp] == ''or slist[tmp] =='#') and tmp > 0:
                        tmp -= 1
                    slist[tmp] = ''
        for i in range(len(tlist)):
            if tlist[i] == '#':
                tlist[i]=''
                if i!=0:
                    tmp = i - 1
                    while (tlist[tmp] == '' or tlist[tmp] =='#')and tmp > 0:
                        tmp -= 1
                    tlist[tmp] = ''
        return ''.join(slist) == ''.join(tlist)
        

```