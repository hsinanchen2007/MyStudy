```
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        n1 = len(nums)
        n2 = len(nums[0])
        sum1 = n1 * n2
        sum2 = r * c
        if sum1 != sum2:
            return(nums)
        else:
            list1 = []
            list2 = []
            for i in nums:
                list1.extend(i)
            num = 0
            for j in range(r):
                list3 = []
                for k in range(c):
                    list3.append(list1[num])
                    num += 1
                list2.append(list3)
            return(list2)
```
