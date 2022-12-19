```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        N=len(nums)
        frontSum=[0]*(N+1)
        for i in range(1,N+1):
            frontSum[i]=frontSum[i-1]+nums[i-1]
        maxValue=0

        queue=[]
        for i in range(0,N+1):
            while queue and frontSum[i]-frontSum[queue[-1]]<=0:
                queue.pop()
            while queue and frontSum[i]-frontSum[queue[0]]>maxValue:
                front=queue[0]
                #queue.pop(0)#这里不需要出队列了
                maxValue=max(maxValue,frontSum[i]-frontSum[front])
                
            queue.append(i)
        if maxValue==0:#说明输入全是非正数
            return max(nums)
            
        return maxValue

```

类似题目参考862. 和至少为 K 的最短子数组