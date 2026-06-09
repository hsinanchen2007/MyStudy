**注意**： 

`第一个有效注释优先于其他注释`

看到这一句就不用分析一大堆`//`和`/*`、`*/`相互包含的情况了。然后用python处理字符串感觉和作弊一样。。
```python
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
                
        string = '\n'.join(source) + '\n'
        
        while '//' in string or '/*' in string:
            multiInd = string.find('/*')
            oneInd = string.find('//')
            
            if(oneInd < multiInd and oneInd != -1) or (multiInd == -1 and oneInd != -1):
                oneEnd = string[oneInd+2:].find('\n') + oneInd + 2
                string = string[:oneInd] + string[oneEnd:]
                
            elif(multiInd < oneInd and multiInd != -1) or (multiInd != -1 and oneInd == -1):
                multiEnd = string[multiInd+2:].find('*/') + multiInd + 2
                string = string[:multiInd] + string[multiEnd+2:]
                
        result = []
        for s in string.split('\n'):
            if s != '':
                result.append(s)
                
        return result
```
评论区老哥的正则表达式的方法更棒。