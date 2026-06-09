```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        list1 = []
        list3 = []
        ret = []
        for i in candidates:
            list1.append(list(range(i,i+1)))
            list2 = list1[:]
        def diedai(l1,l2,target):
            n1 = len(l1)
            for i in range(n1):
                for j in l2:
                    bb = l1[i] + j
                    if sum(bb) <= target:
                        bb.sort()
                        l1.append(bb)
        while list2:
            list3 = []
            for i in list2:
                if sum(i) == target:
                    if i not in ret:
                        ret.append(i)
                    list3.append(i)
                elif sum(i) < target:
                    list3.append(i)
            list2 = list3
            if list2:
                n2 = len(list2)
                diedai(list2,list1,target)
                del list2[0:n2]
            else:
                break
        return(ret)
```
