class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        j = 0
        for c in s:
            #优先满足胃口小的小朋友
            if j >=len(g):
                break
            if c >=g[j]:
                j+=1
        return j
