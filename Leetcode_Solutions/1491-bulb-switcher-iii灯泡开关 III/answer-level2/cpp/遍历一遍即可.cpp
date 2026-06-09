
```
class Solution(object):
    def numTimesAllBlue(self, light):
        """
        :type light: List[int]
        :rtype: int
        """
        ret=0
        n = len(light)
        ison = [False for i in range(n)]
        p = -1 #连续的最右边的灯
        right = -1 # 在p的右边最远的开的灯
        for x in light:
            t = x-1
            ison[t] = True
            if t==p+1:
                while p+1<n and ison[p+1]:
                    p+=1
                if right != -1 and p>=right:
                    right = -1
                    for j in range(p+1,n):
                        if ison[j]:
                            right = j
                            break
            else: right = max(t,right)
            if right == -1 :
                ret+=1
        return ret
```