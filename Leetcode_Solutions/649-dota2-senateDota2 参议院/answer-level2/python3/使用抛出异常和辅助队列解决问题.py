__获胜的关键__
1. Ban掉下一个将要出现的敌人  
2. 如果没有下一个出现的敌人，就从对列头部开始Ban  
3. 如果还是没有，证明队列中已经没有敌人，可以直接宣布获胜  

代码思路：    
建立一个新队列（queue = []），用来储存已经投了票的元素  
现有队列（senate）第一个元素出列，加入queue中的尾部  
先从senate中ban敌人（这里使用的是remove,它会删除第一个出现的指定元素）    
如果抛出异常（ValueError）说明senate中没有敌人，就从queue中ban敌人  
如果再次抛出异常（ValueError）说明queue中也没有敌人，直接宣布获胜  
一轮投票结束后，在已经投过票的人中开始新一轮投票（senate[:] = queue）  
```
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        dic = {'R':['D','Radiant'], 'D':['R','Dire']}
        senate = list(senate)
        while (len(senate)!=1):
            queue = []
            while senate:
                queue.append(senate.pop(0))
                try:senate.remove(dic[queue[-1]][0])
                except ValueError:
                    try:queue.remove(dic[queue[-1]][0])
                    except ValueError:return dic[queue[-1]][1]
            senate[:] = queue
        return dic[senate[0]][1]
```