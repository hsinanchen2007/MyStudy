```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def swap(l,a,b):
            temp = l[a]
            l[a] = l[b]
            l[b] = temp
            return         
        def adjust(array,i):
            max_index = i
            if 2*i+1 < len(array) and array[2*i+1] > array[max_index]:
                max_index = 2*i+1
            if 2*i+2 < len(array) and array[2*i+2] > array[max_index]:
                max_index = 2*i+2
            if max_index != i:
                swap(array,max_index,i)
                adjust(array,max_index)
            return
        #构建大顶堆
        for each in range((len(nums)-1)//2,-1,-1):
            adjust(nums,each)
        r = [0]*len(nums)
        for i in range(len(nums)-1,-1,-1):
            swap(nums,0,i)
            r[i] = nums[-1]
            del nums[-1]
            adjust(nums,0)
        return r
```
