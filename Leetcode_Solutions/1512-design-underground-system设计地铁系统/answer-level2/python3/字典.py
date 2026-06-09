
```
class UndergroundSystem:

    def __init__(self):
        self.In={}
        self.out={}


    def checkIn(self, id, stationName, t):
        self.In[id]=(stationName,t)


    def checkOut(self, id, stationName, t):
        start=self.In[id][0]
        end=stationName
        t1=t-self.In[id][1]
        count=1
        if (start,end) not in self.out.keys():
            self.out[(start,end)]=[t1,count]
        else:
            self.out[(start,end)][0]=self.out[(start,end)][0]+t1
            self.out[(start,end)][1]=self.out[(start,end)][1]+1
                    

    def getAverageTime(self, startStation, endStation):
        return self.out[(startStation, endStation)][0]/self.out[(startStation, endStation)][1]
```
