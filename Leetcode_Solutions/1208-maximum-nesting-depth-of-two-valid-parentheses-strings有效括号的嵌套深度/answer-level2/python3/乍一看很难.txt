每个字符所处深度可以根据从左侧到当前位置'('的数目减去')'的数目得到。
为了最小化a和b的深度差，从头开始遍历字符串，如果在a深度更深的情况下遇到'('就分配给b，其余的情况同理。

```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        da=0
        db=0
        ans=[]
        for i in range(len(seq)):
            if seq[i]=='(':
                if da>db:
                    ans.append(1)
                    db+=1
                else:
                    ans.append(0)
                    da+=1
            else:
                if da>db:
                    ans.append(0)
                    da-=1
                else:
                    ans.append(1)
                    db-=1
            #print(da,db,ans)
        return ans
```
