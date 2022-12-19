```python3
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        '''最笨解，就是建立结果时刻表，还有已经访问的节点'''
        lst=[0]*n
        '''图的建立可以通过popedge防止回溯'''
        lst[0]=1
        start=[1]
        for _ in range(t):
            if len(edges)==0:
                break
            next=[]
            
            for i in start:
                #print(i)
                sum=0
                
                temp=[]
                index_2_delet=[]
                for index,u in enumerate(edges):
                    if u[0]==i or u[1]==i:
                        
                        #temp.append(index)
                        index_2_delet.append(index)
                        sum=sum+1
                        next.append(u[1] if u[0]==i else u[0])
                        temp.append(u[1] if u[0]==i else u[0])
                if sum!=0:
                    for k in reversed(index_2_delet):
                        edges.pop(k)  
                    for k in temp:
                        lst[k-1]=lst[i-1]/sum
                    lst[i-1]=0
                
                
            start=next
           # print(lst,next,edges)
            
        return lst[target-1]
```
