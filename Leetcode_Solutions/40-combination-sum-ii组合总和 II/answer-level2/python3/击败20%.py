```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        zidian1 = {}
        for it in candidates:
            zidian1[it] = candidates.count(it)
        list1 = []
        list3 = []
        ret = []
        for i in candidates:
            if i <= target:
                list1.append(list(range(i,i+1)))
        list2 = list1[:]
        cishu1 = len(list1)
        cishu2 = int(target / min(candidates)) + 1
        cishu = min(cishu1,cishu2)
        def diedai(l1,l2,target):
            n3 = len(l1)
            for i in range(n3):
                for j in l2:
                    bb = l1[i] + j
                    if sum(bb) < target:
                        bb.sort()
                        if bb not in l1:
                            l1.append(bb)
                    elif sum(bb) == target:
                        bb.sort()
                        if bb not in ret:
                            flg = "bb"
                            for iti in bb:
                                if zidian1[iti] < bb.count(iti):
                                    flg = "xx"
                                    break
                            if flg == "bb":
                                ret.append(bb)
        for i in list2:
            if sum(i) == target:
                if i not in ret:
                    ret.append(i)
            elif sum(i) < target:
                list3.append(i)
        list2 = list3
        for jb in range(cishu - 1):
            if list2:
                n2 = len(list2)
                diedai(list2,list1,target)
                del list2[0:n2]
            else:
                break
        return(ret)
```
