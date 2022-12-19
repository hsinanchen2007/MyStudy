```
class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        pick_drop=[] #记录所有的人数，起始点，下车点信息
        curr_capacity=0
        for i in range(len(trips)): #建立成元组形式进行储存
            pick_drop.append((trips[i][0],trips[i][1],"s"))
            pick_drop.append((trips[i][0],trips[i][2],"d"))
        def getkey(item):
            return item[1]
        pick_drop = sorted(pick_drop,key=lambda x: (x[1],x[2])) #注意如果地点一样，要先下车再上车，不然会有问题
        for each in pick_drop:
            if each[2]=="d": #下车，减人数
                curr_capacity -= each[0] # 
            else:
                curr_capacity += each[0] #上车，加人数
                if curr_capacity>capacity: #超重了
                    return False
        return True
```
