### 解题思路
代码：
    解释不清，自己看。
执行用时 :56 ms, 在所有 Python3 提交中击败了92.45%的用户
内存消耗 :14.9 MB, 在所有 Python3 提交中击败了5.33%的用户
### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        a=0
        b=False
        c=[]
        for i in range(len(nums)-1):
            if nums[i]==nums[i+1]:
                b=True
                c.append(i)
                c.append(i+1)
        if b:
            for i in range(len(nums)-1):
                if nums[i]>nums[i+1]:
                    if c[len(c)-1]==len(nums)-1:
                        nums[i]=nums[i+1]
                        a+=1
                    else:
                        nums[i+1]=nums[i]
                        a+=1
                if a==1:
                    break
        else:    
            for i in range(len(nums)-1):
                if nums[i]>nums[i+1]:
                    if i+1==len(nums)-1:
                        nums[i+1]=nums[i]
                    else:
                        if nums[i-1]>nums[i+1] and i!=0:
                            nums[i+1]=nums[i]
                        nums[i]=nums[i+1]
                        a+=1
                if a==1:
                    break
            
        for i in range(len(nums)-1):
            if nums[i]<=nums[i+1]:
                pass
            else:
                return False
        return True
```