### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums)==0:
            return []
        end=k-1
        start=0
        res=float("-inf")
        for i in range(start,end+1):
            if nums[i]>res:
                res=nums[i]
        result=[res,]
        size=len(nums)
        while end < size-1:#end=0
            end+=1
            start+=1
            if nums[end]>res:#如果最后增加的元素比之前的大更新元素。
                res=nums[end]
                result.append(res)
            else:#如果新进入的元素不比之前的大，如果画出的不是最大值则直接增加原来的
                if nums[start-1] != res:
                    result.append(res)
                else:
                    #求更新的窗口的最大值
                    res=float("-inf")
                    for i in range(start,end+1):
                        if nums[i]>res:
                            res=nums[i]
                    result.append(res)
                                

        return result

            



```