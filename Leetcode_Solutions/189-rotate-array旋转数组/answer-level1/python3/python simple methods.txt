### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        '''
        k%=len(nums)
        nums[:] = nums[-k:]+nums[:-k]
        #nums[:] = nums[::-1]
        #nums[:k] = nums[:k][::-1]
        #nums[k:] = nums[k:][::-1]
        '''

        '''
        n = len(nums)
        k%=n
        def swap(l,r):
            while l<r:
                nums[l],nums[r] = nums[r],nums[l]
                l+=1
                r-=1
        swap(0,n-k-1)
        swap(n-k,n-1)
        swap(0,n-1)
        '''

        '''
        for i in range(len(nums)-k%len(nums)):
            nums.append(nums[0])
            nums.pop(0)
        '''

        k%=len(nums)
        for _ in range(k):
            nums.insert(0,nums.pop())
```