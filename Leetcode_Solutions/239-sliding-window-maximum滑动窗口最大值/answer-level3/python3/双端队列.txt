
```
from collections import deque
class Solution:
    def maxSlidingWindow(self, nums, k):
        #定义一个list存储滑动窗口最大值的结果
        result=[]

        #特殊情况判断
        if not nums or k<=0 or len(nums)==0:
            return result

        #定义一个双端队列
        d=deque([])

        for i in range(len(nums)):

            if d and i-d[0]>=k:
                    d.popleft()

            #如果队列不为空 
            while d:
                #第一种：如果下一个数比队头元素小，则入队
                if nums[i]<=nums[d[-1]]:#d[-1]代表最右边的数
                    #d.append(i)
                    break
                #第二种：反之，则将下个数和当前队头，以及队列前面的数进行比较，直到队列里面的数大于等于下一个数
                else:
                    d.pop()
            #如果队列为空，入队
            d.append(i)
            
            if i>=k-1:
                result.append(nums[d[0]])
        return result
        
if __name__ == "__main__":
    s=Solution()
    nums = [6,2,-1,0]
    k=3
    print(s.maxSlidingWindow(nums, k))
```