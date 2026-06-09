```
class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        # 1.用defaultdict O(n) with extra O(n) space
        # from collections import defaultdict
        # ans, d = [], defaultdict(list)
        # for i, score in items:
        #     d[i].append(score)  # 把所有的数都加进去
        # for k, v in d.items():
        #     ans.append([k, int(sum(sorted(v)[-5:]) / 5)])
        # return ans
    
        # 2. 把方法一优化一下 O(n) without extra space
        from collections import defaultdict
        d = defaultdict(list)
        for i, score in items: # 只加最大的5个数进去
            if len(d[i]) >= 5:
                min_num = min(d[i]) 
                d[i].remove(min_num) # 抛弃最小数
                d[i].append(max(score, min_num))
            else:
                d[i].append(score)  
        return [[k, int(sum(v) / 5)] for k, v in d.items()]
```
