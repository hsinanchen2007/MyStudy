将原数组头尾补1，该问题可转化为求连续为0的字串长度。
遍历该数组，start记录从1到0的跳转位置，如果发生了从0到1跳转，计算当前位置与start距离gap(即为一个连续为0的字串长度)，如果start==1 or i==len(seats)-1，说明子串开头或结尾在原数组开头或结尾位置，此时可坐开头或结尾；否则只可坐中间位置。
```
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        seats.insert(0,1)
        seats.append(1)
        start=0
        res=0
        for i in range(1,len(seats)):
            if seats[i]==0 and seats[i-1]==1:
                start=i
            if seats[i]==1 and seats[i-1]==0:                
                gap=i-start
                if start==1 or i==len(seats)-1:
                    res=max(res,gap)
                else:                       
                    res=max((gap-1)//2+1,res)
        return res
        
```
