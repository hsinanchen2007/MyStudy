[0,1,0,2,1,0,1,3,2,1,2,1]
1.先把左右两头的平地挖掉。
[1,0,2,1,0,1,3,2,1,2,1]
2.再按左右两堵墙矮的为基准，把地平面向下挖这个高度。
[0,-1,1,0,-1,0,2,1,0,1,0]
3.负数代表挖出了洞，浇水泥填平，共浇水泥2单位
[0,0,1,0,0,0,2,1,0,1,0]
循环前三步直到地被挖完，记录水泥浇灌量。

```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        def removeHeadZero(l):
            while 1:
                if len(l)==0 or l[0]>0:
                    break
                else:
                    l.pop(0)
                    
        def removeTailZero(l):
            while 1:
                if len(l)==0 or l[-1]>0:
                    break
                else:
                    l.pop(len(l)-1)
                    
        def digDown(l):
            if l:
                minHeight = min(l[0], l[-1])
                i = 0
                while i<len(l):
                    l[i]-=minHeight
                    i+=1
                
            
        
        def calcWater(l):
            if len(l)<=2:
                return 0
            removeHeadZero(l)
            removeTailZero(l)
            digDown(l)
            n=0
            for i in range(0,len(l)):
                if l[i]<0:
                    n-=l[i]
                    l[i]=0
            return n+calcWater(l)
          
        return calcWater(height)
        
```    

                
        
                

