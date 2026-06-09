```
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        count = 0

        def merge(nums,start,middle,end):
            p1 = middle
            p2 = end
            nonlocal count
            temp = [0 for i in range(end-start+1)]
            i = end-start
            while p1 >= start and p2 >= middle+1:
                if nums[p1] > nums[p2]:  # 第一个元素更大，记录一下并排序
                    count += (p2-middle)
                    temp[i] = nums[p1]
                    p1 -= 1
                else:
                    temp[i] = nums[p2]
                    p2 -= 1
                i -= 1
            while p1 >= start:
                temp[i] = nums[p1]
                p1 -= 1
                i -= 1
            while p2 >= middle+1:
                temp[i] = nums[p2]
                p2 -= 1
                i -= 1
            nums[start:end+1] = temp


        def mergeSort(nums,start,end):
            if start >= end:
                return
            middle = (start+end)//2
            mergeSort(nums,start,middle)
            mergeSort(nums,middle+1,end)
            merge(nums,start,middle,end) 

        mergeSort(nums,0,len(nums)-1)
        return count

```
