```
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        count = 0
        p1 = 0
        p2 = 0
        #将两个指针从左向右遍历列表
        while p1 < len(g) and p2 < len(s):
            #如果能够找到满足胃口值的饼干则count+=1并移动两个指针到下一位小朋友和饼干
            if g[p1]<=s[p2]:
                count+=1
                p1+=1
                p2+=1
            #如果不能满足最小胃口值的小朋友则使用更大的饼干进行尝试
            else:
                p2+=1
        return count
```
