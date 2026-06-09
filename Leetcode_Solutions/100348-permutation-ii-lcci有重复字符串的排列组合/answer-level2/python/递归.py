直接上代码看注释吧，思路就是算出每个字母的个数，然后用一个减一个
```
class Solution:
    def permutation(self, S: str) -> List[str]:
        if not S:
            return []
        
        counter = collections.Counter(S)  # 计算每个字母个数
        n = len(S)
        res = []

        def helper(tmp):
            if len(tmp) == n:
                res.append(tmp)
                return
            for s in counter:
                if counter[s]:  # s个数不为0
                    counter[s] -= 1  # s个数减一
                    helper(tmp + s)  # 递归
                    counter[s] += 1  # 别忘了加回来
        
        helper('')
        return res
```
