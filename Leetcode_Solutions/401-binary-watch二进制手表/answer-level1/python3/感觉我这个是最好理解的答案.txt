
```
from itertools import *
class Solution:
    def dfs(self,num,n_hours,res):
        if n_hours>4 or n_hours>num: return
        
        n_minutes=num-n_hours
        # Each of 4 hour leds stands for: 1,2,4,8
        hour_list=[2**i for i in range(4)]
        
        # Each of 6 minutes leds stands for: 1,2,4,8,16,32
        minute_list=[2**i for i in range(6)]

        # Valid hour combinations
        hour_comb=[sum(i) for i in combinations(hour_list,n_hours) if sum(i)<12]
        
        # Valid minute combinations
        minute_comb=[sum(i) for i in combinations(minute_list,n_minutes) if sum(i)<60]
        
        # Valid time list
        valid_time_list=[i for i in product(hour_comb,minute_comb)]
        
        # Convert time list into time string in format: "h:mm"
        for i in valid_time_list:
            res.append('{:d}:{:02d}'.format(i[0],i[1]))
        
        # Call self for next n_hour bit number
        self.dfs(num,n_hours+1,res)
        
    def readBinaryWatch(self, num: int) -> List[str]:
        res=[]
        self.dfs(num,0,res)
        return res
```
