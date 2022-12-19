```
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        if not deck:
            return False
        
        import collections
        c = collections.Counter(deck)
        values = list(set(c.values()))
        min_v = min(values)
        if min_v < 2:
            return False

        s = []
        for i in range(2, min_v+1):
            if min_v // i * i == min_v:
                s.append(i)
        
        for val in c.values():
            for i in s:
                if val % i != 0:
                    s.remove(i)
            if not s:
                return False

        return True
```
求出所有牌的数量，找到最小数，求出最小数所有因子，遍历数量，如果某个数量不能被因子整出，移除因子，一但剩余因子为空，即可return False
执行用时 :140 ms, 在所有 python 提交中击败了97.48%的用户

