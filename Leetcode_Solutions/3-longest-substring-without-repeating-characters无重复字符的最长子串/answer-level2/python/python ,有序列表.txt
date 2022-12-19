class Solution(object):
    def lengthOfLongestSubstring(self, s):
        d = []
        b = []
        for x in s:
            if x not in d:
                d.append(x)
            else:
                b.append(len(d))
                d = d[d.index(x)+1:]
                d.append(x)
            b.append(len(d))
        if len(b) > 0:
            return max(b)
        else:
            return 0