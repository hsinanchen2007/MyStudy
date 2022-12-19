这题很明显maxSize没有用，因为长的串重复它的子串一定也重复，然后按照数据范围可知不需要滑动窗口来优化，复杂度O(len(s)*minSize),比赛时我的代码如下：
```
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        n=len(s)
        d=collections.defaultdict(int)
        for i in range(n-minSize+1):
            temp=s[i:i+minSize]
            c=set(temp)
            if len(c)<=maxLetters:
                d[temp]+=1
        return max(d.values()) if d else 0
```
