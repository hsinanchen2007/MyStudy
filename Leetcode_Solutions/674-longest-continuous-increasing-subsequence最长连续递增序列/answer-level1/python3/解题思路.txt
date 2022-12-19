### 解题思路
nums长度为1或0时max[res]会出错，因为此时res=[]
count从1计数，注意最后一个数判断完之后要把count添加到res,因为循环结束了

### 代码

```python3
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        res=[]
        count=1
        if nums==[]:
            return 0
        if len(nums)==1:
            return 1
        for i in range(len(nums)-1):
            if nums[i+1]>nums[i]:
                count+=1
                if i==len(nums)-2:
                    res.append(count)
            else:
                res.append(count)
                count=1
        return max(res)

```