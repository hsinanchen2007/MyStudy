```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        list1 = []
        list2 = []
        n1,n2 = len(nums),0
        while n2 < n1:
            if list1 == []:
                for i in nums:
                    list1.append([i])
            else:
                list2 = []
                for j in list1:
                    for k in nums:
                        if j.count(k) < nums.count(k):
                            l = j[:]
                            l.append(k)
                            if l not in list2:
                                list2.append(l)
                        else:
                            pass
                list1 = list2
            n2 += 1
        return(list1)

```
