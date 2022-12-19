### 解题思路
此处撰写解题思路
用if..else循环，保留上个状态，往下循环，与上个转相反，那么长度加1

### 代码

```python
class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<2:
            return len(nums)

        BEGIN=0
        UP=1
        DOWN=2
        i=1
        state=BEGIN
        maxlength=1
        while(i<len(nums)):
            if(state==BEGIN):
                if(nums[i]>nums[i-1]):
                    state=UP
                    maxlength+=1
                    i+=1
                    continue
                elif(nums[i]<nums[i-1]):
                    state=DOWN
                    maxlength+=1
                    i+=1
                    continue
                else:
                    i+=1
            elif(state==UP):
                if(nums[i]<nums[i-1]):
                    state=DOWN
                    maxlength+=1
                    i+=1
                else:
                    i+=1
            elif(state==DOWN):
                if(nums[i]>nums[i-1]):
                    state=UP
                    maxlength+=1
                    i+=1
                else:
                    i+=1
            else:i+=1
        return maxlength

                    

```