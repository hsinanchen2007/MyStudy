非注释区记录字符
非注释区遇见//本行结束
非注释区遇见/*开始注释，位置移动2格。
注释区遇见*/结束注释，位置移动2格。
行结尾，若内容大于0，非注释区，加入结果。
注释区留给下一次，除非整个结尾。

因为想不起来注释英文是什么，姑且用靶子target命名。

48ms
```
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        ans=[]
        tar=False
        i=0
        while i<len(source):
            j=0
            temp=''
            if tar:
                temp=lasttemp
            while j<len(source[i]):
                if j+1<len(source[i]):
                    if not tar and source[i][j:j+2]=='/*':
                        tar=True
                        lasttemp=temp
                        j+=2
                        continue
                    elif tar and source[i][j:j+2]=='*/':
                        tar=False
                        j+=2
                        continue
                    elif not tar and source[i][j:j+2]=='//':
                        break
                if not tar:
                    temp=temp+source[i][j]
                j+=1
            if len(temp)>0 and( (not tar)or i==len(source)-1):
                ans.append(temp)
            i+=1
        return ans
```
