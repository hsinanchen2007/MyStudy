```
class Solution(object):
    def groupThePeople(self, groupSizes):
        dic = collections.defaultdict(list)
        for i in groupSizes:
            dic[i].append(i)

        res = []
        index = 0
        for key,value in dic.items():
            groups = len(dic[key]) / key
            for j in range(groups):
                res.append([])
                res[index] = dic[key][key*j:key*(j+1)]
                index += 1
        return res
```
