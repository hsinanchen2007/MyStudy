```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        return self.yanghui(rowIndex)
    
    def yanghui(self,c,pre = [1]):
        if not c:
            return pre
        if pre == [1]:
            if pre==[1] and c == 1:
                return [1,1]
            return self.yanghui(c-1,[1,1])
        else:
            return self.yanghui(c-1,[1] + [pre[x-1] + pre[x] for x in range(1,len(pre))] +[1])
            
```
