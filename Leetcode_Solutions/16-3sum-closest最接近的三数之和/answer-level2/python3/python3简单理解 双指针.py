先对nums进行排序，选定最左侧的一个数字，以及左右侧各放置一个指针

每次判断三者之和，如果等于target，直接返回target的值
否则：判断差值的正负，如果为负，说明靠近target的方向为向右，则将左指针向右一定一格
     如果为正，则将右指针向左移动一格

更新差值和三数之和：将更小的差值和三数之和储存


```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        
        inf = float("inf") 
        nums.sort()
        for i in range(len(nums)-2):
            left=i+1                 #左指针
            right=len(nums)-1        #右指针
            while(right>left):
                temp=nums[i]+nums[left]+nums[right]
                if temp==target: 
                    return target
                else:
                    diff = target-temp   # 差值
                    if diff<0:right-=1   # 太大了，右指针左移
                    if diff>0:left+=1    # 反之
                    if abs(diff)<inf:    # 更新差值
                        inf=abs(diff)
                        res=temp
        return res
```
