执行用时:36 ms, 在所有 Python3 提交中击败了96.87%的用户
```
class Solution:
    def binary_search(self,num,tar,left,right,if_find_left):
        while left<=right:
            mid=(left+right)//2
            if num[mid]<tar:
                left=mid+1
            elif num[mid]>tar:
                right=mid-1
            else:
                return mid
        return left if if_find_left else right

    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l,r=0,len(numbers)-1
        while l<r:
            sum_=numbers[l]+numbers[r]
            if sum_<target:
                l=self.binary_search(numbers,target-numbers[r],left=l+1,right=r,if_find_left=True)
            elif sum_>target:
                r=self.binary_search(numbers,target-numbers[l],left=l,right=r-1,if_find_left=False)
            else:
                return [l+1,r+1]
```
