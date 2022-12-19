```
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        i=0
        flag=False  #是否进入注释块
        while i<len(source):
            if "/" in source[i]:    #有可能存在注释符号
                j=0
                while j<len(source[i])-1:   #-1
                    if not flag and source[i][j]=="/" and source[i][j+1]=="/":  #处理行注释
                        source[i]=source[i][:j]
                        break
                    if not flag and source[i][j]=="/" and source[i][j+1]=="*":
                        start=(i,j)
                        flag=True
                        j+=2    #注意j要+2，避免/*/的情况，这种情况并不表示注释结束
                        continue
                    if flag and source[i][j]=="*" and source[i][j+1]=="/":
                        end=(i,j+2)
                        flag=False
                        source[end[0]]=source[start[0]][:start[1]]+source[end[0]][end[1]:]  #当前行尺寸变了，改变end行比较好，因为*/过后也许还会出现注释，还需要处理
                        for k in range(start[0],end[0]):
                            source[k]=""
                        j=start[1]  #j要变的
                        continue
                    j+=1
            i+=1
        #清除空白
        n=len(source)
        i=0
        while i<n:
            if source[i]=="":
                del source[i]
                n-=1
                continue
            i+=1
        return source
```
