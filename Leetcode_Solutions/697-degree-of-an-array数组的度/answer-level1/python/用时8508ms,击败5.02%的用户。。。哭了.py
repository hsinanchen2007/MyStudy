### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        ans=[]
        dic={}
        for i in nums:
            if i not in dic.keys():
                dic[i]=0
            dic[i]+=1
        #print(dic)
        #return

        target=max(dic.values())
        #return

        for i in dic.keys():
            if dic[i] ==target:
                left=0
                right=len(nums)-1
                while left<=right:
                    if nums[left]==nums[right]==i:
                        ans.append(right-left+1)
                        break
                    if nums[left]!=i:
                        left+=1
                    if nums[right]!=i:
                        right-=1
        
        return min(ans)
                    



        
```