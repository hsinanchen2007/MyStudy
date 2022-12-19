class Solution:
    def __init__(self):
        self.cache = {}
    def encode(self, s):
        if len(s) < 5:
            return s
        if s in self.cache:
            return self.cache[s]
 
        n = len(s)
        mid = n // 2
        res = s
        for i in range(1, mid + 1):
            j, count, match = i, 1, s[:i]
            while match == s[j:j+i]:
                count += 1
                j += i
                res_1 = "{}[{}]{}".format(count, self.encode(match), self.encode(s[j:]))
                if len(res_1) < len(res):
                    res = res_1
                if i + j > n: break
        next = s[0] + self.encode(s[1:])
        if len(next) < len(res):
            res = next
        self.cache[s] = res
        return res