class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        check=0
        a=1
        sumit=0
        co=0
        for i in light:
            check=check+a
            a=a+1
            sumit=sumit+i
            if(sumit==check):
                co=co+1
        return co