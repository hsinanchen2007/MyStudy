### 解题思路
进行列表化处理后可以慢慢进行判断是否一一对应

### 代码
执行用时 :
20 ms
内存消耗 :
12.6 MB
```python
class Solution(object):
    def wordPattern(self, pattern, str):

        o=list(pattern)
        s=str.split()#都列表化

        w={}#字典

        r=0#手动迭代对象
        if len(s)!=len(o):
            return False
        for i in o:
            if i not in w:
                
                if s[r] in w.values():
                    return False
                w[i]=s[r]  

            elif s[r]!=w[i]:
                return False

            r+=1
        return True



```