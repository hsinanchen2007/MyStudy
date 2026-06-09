class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        bucket=[0]*101
        for height in heights:
            bucket[height]+=1
        count=0
        j=0
        for i in range(1,101):
            while bucket[i]>=1:
                if heights[j]!=i:
                    count+=1
                j+=1
                bucket[i]-=1
        return count