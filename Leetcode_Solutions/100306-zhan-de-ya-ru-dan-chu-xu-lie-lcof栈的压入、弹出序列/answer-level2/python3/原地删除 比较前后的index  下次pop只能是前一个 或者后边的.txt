- 可以把pushed里面检查到的数字删了，然后直接对比pushed数组前后两个index。当cur-pre<-1的时候返回False
```
def _delete(self,s,t):
        index = s.index(t.pop(0))
        s.pop(index)
        pre = index
        while t:
            # print(s,t)
            cur = s.index(t.pop(0))
            # print(pre,cur)
            if cur-pre<-1:
                return False
            s.pop(cur)
            pre = cur
        return True
```
