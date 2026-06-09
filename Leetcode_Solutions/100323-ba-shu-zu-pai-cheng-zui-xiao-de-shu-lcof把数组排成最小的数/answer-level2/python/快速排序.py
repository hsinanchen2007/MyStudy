- 比较两个数字字符串 可以直接比较str(a)+str(b) <= str(b)+str(a)
- 快速排序左右节点的选择和 先遍历的顺序 很关键 选左节点做base，right指针先动；选右边节点为base，左边指针先动。
```
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        def quick(arr,low,high):
            left,right = low,high
            base = arr[right]
            while left<right:
                while left<right and comp(arr[left],base):
                    left += 1
                arr[right] = arr[left]

                while left<right and comp(base,arr[right]):
                    right -= 1
                arr[left] = arr[right]
            
            arr[right] = base
            piv = right
            
            if low<high:
                quick(arr,low,piv-1)
                quick(arr,piv+1,high)
        
        def comp(a,b):
            return str(a)+str(b) <= str(b)+str(a)
        
        quick(nums, 0, len(nums)-1)
        res = ''
        for num in nums:
            res += str(num)
        return res
```
