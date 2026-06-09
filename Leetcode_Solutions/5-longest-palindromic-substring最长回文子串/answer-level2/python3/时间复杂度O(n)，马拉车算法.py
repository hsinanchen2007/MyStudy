以下是提交通过代码的，详细的过程介绍见[马拉车算法详解](https://zhuanlan.zhihu.com/p/67559846)
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def getExpandLength(left, right, s):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return right - left - 1

        if len(s) < 2: return s
        s = '#' + '#'.join(list(s)) + '#'
        p = [0 for x in range(len(s))]
        max_id = -1
        max_radius = -1
        c = -1
        mx = -1
        for i in range(len(s)):
            if i > mx:
                radius = getExpandLength(i, i, s) // 2
                p[i] = radius
                c = i
                mx = i + radius
                if radius > max_radius:
                    max_id, max_radius = i, radius
            else:
                j = 2*c - i
                if j - p[j] > 2 * c - mx:
                    p[i] = p[j]
                elif j - p[j] < 2 * c - mx:
                    p[i] = mx - i
                else:
                    radius = getExpandLength(i-p[j]-1, i+p[j]+1, s) // 2
                    p[i] = radius
                    if i + radius > mx:
                        c = i
                        mx = i + radius
                    if radius > max_radius:
                        max_id, max_radius = i, radius
        return s[max_id-max_radius:max_id+max_radius+1].replace('#', '')
```
