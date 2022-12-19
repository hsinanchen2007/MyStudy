```python
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ''
        map = {}
        for i in s :
            if i not in map:
                map[i] = 1
            else :
                map[i] += 1
        l = sorted(map.items(), key=lambda x: x[1], reverse=True)
        for v , k in l:
            res += v*k
     return res