```python
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        count = sorted(collections.Counter(s).items(), key=lambda x:-x[1])
        ans = ''
        for i, c in count:
            ans += i*c
        return ans