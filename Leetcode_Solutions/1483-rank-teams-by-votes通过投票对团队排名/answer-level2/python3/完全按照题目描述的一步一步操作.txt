思路和题目描述一样，先看「排位第一」的票的多少决定，这里进行一次排序，迭代下去
```python []
# 下面写上代码块
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        tmp = list(zip(*votes))
        n = len(tmp)
        persons = [i for i in votes[0]]
        from collections import Counter, defaultdict

        def rank_k(persons_k: List[chr], votes_k: int) -> str:
            if len(persons_k) == 1:
                return persons_k[0]
            if votes_k >= n:
                persons_k.sort()
                return ''.join(persons_k)
            votes_cur = Counter(tmp[votes_k])
            votes_person_dict = defaultdict(list)
            for person in persons_k:
                votes_person_dict[votes_cur[person]].append(person)
            keys = list(votes_person_dict.keys())
            keys.sort(reverse=True)
            res = ''
            for k in keys:
                res += rank_k(votes_person_dict[k], votes_k+1)
            return res

        return rank_k(persons, 0)
```
`执行用时：44 ms
内存消耗：14.5 MB`