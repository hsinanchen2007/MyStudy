```python
'''
暴力出奇迹，根据规则去做，先统计a,b在pattern中的数量，然后收集a,b可能对应的长度，遍历一遍即可。
'''
class Solution:
    def patternMatching(self, pattern: str, value: str) -> bool:
        dic = collections.Counter(pattern)
        n_a = dic.get('a',0)
        n_b = dic.get('b',0)
        if n_a == 0 and n_b==0:
            return not value 
        if n_a == 0:
            return (len(value)%n_b==0) and n_b*value[:len(value)//n_b] == value
        if n_b == 0:
            return (len(value)%n_a==0) and n_a*value[:len(value)//n_a] == value

        candidate = []
        m = len(value)//n_a
        for i in range(0, m+1):
            if (len(value)-i*n_a)%n_b == 0:
                candidate.append([i, (len(value)-i*n_a)//n_b])
        
        for i,j in candidate:
            if self.check(pattern, value, i, j):
                return True
        return False

    def check(self, pattern, value, i, j):
        set1 = set()
        set2 = set()
        for c in pattern:
            if c == 'a':
                if set1 and value[:i] not in set1:
                    return False
                set1.add(value[:i])
                value = value[i:]
            elif c == 'b':
                if set2 and value[:j] not in set2:
                    return False
                set2.add(value[:j])
                value = value[j:]
        if set1 == set2:        ## a,b对应模式相同返回False
            return False
        return True



