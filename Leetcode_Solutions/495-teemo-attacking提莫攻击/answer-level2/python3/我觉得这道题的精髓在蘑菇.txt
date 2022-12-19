class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if timeSeries==[]:
            return 0
        time=duration
        for i in range(len(timeSeries)-1):
            if (timeSeries[i+1]-timeSeries[i])>=duration:
                time+=duration
            else:
                time+=timeSeries[i+1]-timeSeries[i]
        return time