
```python []
class Solution(object):
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        import collections
        a_dict = {}
        a_dict=collections.OrderedDict()
        for i in sorted(A):
            a_dict[i] = a_dict.get(i) and a_dict[i] + 1 or 1
        for i in a_dict:
            if a_dict[i] == 0:
                continue
            else:
                if i > 0:
                    s = i * 2
                else:
                    if i % 2 == 0:
                        s = i / 2
                    else:
                        return False
                if  a_dict.get(s):
                    a_dict[s] = a_dict[s] - a_dict[i]
                else:
                    return False
        return True
```