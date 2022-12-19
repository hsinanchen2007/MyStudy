思路：
1.通过有顺序的排列组合，获取所有的可能性
2.通过一个升序和一个降序的filter进行过滤
3.输出过滤后的列表的长度
```

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        def filter1(ge):
            for i in range(len(ge)-1):
                if ge[i] < ge[i+1]:
                    continue
                else:
                    return False
            return True

        def filter2(ge):
            for i in range(len(ge)-1):
                if ge[i] > ge[i+1]:
                    continue
                else:
                    return False
            return True

        def good(ge):
            if filter1(ge) or filter2(ge):
                return True
            else:
                return False
        from itertools import permutations,combinations
        data = rating
        temp = []
        for i in combinations(data,3):
            temp.append(i)
        result = filter(good, temp)
        result = [i for i in result]
        return len(result)
```
