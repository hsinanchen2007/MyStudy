```
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
    	dict1={}
    	for i in range(R):
    		for j in range(C):
    			dict1[str(i)+'+'+str(j)]=abs(i-r0)+abs(j-c0)
    	dict2=sorted(dict1.items(),key=lambda item:item[1])//对字典的值进行排序
    	re=[]
        
    	for i in dict2:
    		x,y=i[0].split('+')[0],i[0].split('+')[1]
    		re.append([int(x),int(y)])
    	return re
```