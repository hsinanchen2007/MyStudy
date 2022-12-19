

### 代码

```python3
class MedianFinder:
    def __init__(self):
        self.lnums=[]
        self.hnums=[]
    def addNum(self, num: int) -> None:
        if not self.lnums or num<=self.lnums[0]:
            self.lnums.append(num)
            self.uplnums()
        else:
            self.hnums.append(num)
            self.uphnums()
        if len(self.lnums)<len(self.hnums):
            self.hnums[0],self.hnums[len(self.hnums)-1]=self.hnums[len(self.hnums)-1],self.hnums[0]
            self.lnums.append(self.hnums.pop())
            self.downhnums()
            self.uplnums()
        elif len(self.lnums)>1+len(self.hnums):
            self.lnums[0],self.lnums[len(self.lnums)-1]=self.lnums[len(self.lnums)-1],self.lnums[0]
            self.hnums.append(self.lnums.pop())
            self.downlnums()
            self.uphnums()

    def findMedian(self) -> float:
        if len(self.lnums)>len(self.hnums):
            return self.lnums[0]
        else:
            return (self.lnums[0]+self.hnums[0])/2
    def uplnums(self):
        j=len(self.lnums)-1
        p=(j-1)//2
        while j>0 and self.lnums[j]>self.lnums[p]:
            self.lnums[j],self.lnums[p]=self.lnums[p],self.lnums[j]
            j=p
            p=(j-1)//2
    def downlnums(self):
        j=0     
        while 2*j+1<len(self.lnums):
            big=2*j+1
            if big+1<len(self.lnums):
                if self.lnums[big+1]>self.lnums[big]:
                    big+=1
            if self.lnums[big]>self.lnums[j]:
                self.lnums[j],self.lnums[big]=self.lnums[big],self.lnums[j]
                j=big
            else:
                break

    def uphnums(self):
        j=len(self.hnums)-1
        p=(j-1)//2
        while j>0 and self.hnums[j]<self.hnums[p]:        
            self.hnums[j],self.hnums[p]=self.hnums[p],self.hnums[j]
            j=p
            p=(j-1)//2
    def downhnums(self):
        j=0
        while 2*j+1<len(self.hnums):
            small=2*j+1
            
            if small+1<len(self.hnums):
                if self.hnums[small+1]<self.hnums[small]:
                    small+=1
            if self.hnums[small]<self.hnums[j]:
                self.hnums[j],self.hnums[small]=self.hnums[small],self.hnums[j]
                j=small
            else:
                break
```