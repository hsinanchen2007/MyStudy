
先码下code..
```
class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        id_list = list(set([i for i,j in items]))
        res = []
        for id_1 in id_list:
            score_arr = []
            for ids,scores in items:
                if id_1 == ids:
                    score_arr.append(scores)
            sums = sum(sorted(score_arr,reverse=True)[:5])
            res.append([id_1,int(sums/5)])
        return res
```
