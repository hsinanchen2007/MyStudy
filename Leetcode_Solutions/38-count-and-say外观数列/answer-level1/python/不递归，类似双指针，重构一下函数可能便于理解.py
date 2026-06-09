```
class Solution:
    def countAndSay(self, n: int) -> str:
        def Say(nums:str)->str:
            result=''
            left,right=0,1
            while right < len(nums):
                if nums[right] == nums[left]:
                    right+=1
                else:
                    result+=str(right-left)
                    result+=nums[left]
                    left=right
            result+=str(right-left)
            result+=nums[left]
            return result

        result='1' if n == 1 else '11'
        for i in range(n-2):
            result=Say(result)
        return result
```
