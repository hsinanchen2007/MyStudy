### 解题思路
这个题目以灌溉为主题，我一开始以为会是一个关于面积覆盖的问题。然而这是一个一维的问题，当我们将每个水龙头覆盖的区域，看做从左边开始，右边结束的一道线段，那么题目就转化成经典的跳跃问题，即从0点开始，知道每个位置能向后跳多远，试问最少花多少步能跳到终点。

至于转化的规则，
对于轴上的每一个点 i ，令 d = ranges[i],那么 令left =  (i - d) or 0, right = i+ d,
那么jumps[left] = right ,表示从 left位置,能直接覆盖到right位置。

有的时候，两处水龙头算出的left是相同的，此时就取最大值即可。通过这个方式过滤掉那些被全覆盖的龙头。

当jumps数组完成，我们就能知道从某点出发，最远可以跳到多远。
这样我们就使用跳跃问题常用的贪心思路。
以lp代表本次需要检索的龙头左边位置，(也就是跳过之前所有已检索的龙头位置)，
rp代表本次需要检索的龙头右边位置，
遍历中间的龙头i，取其lines[i],找到其中最大的数字，就标志着，本轮最远可以灌溉到的龙头位置为R。
注意如果R 小于等于 rp, 这代表我们无法再向右跳跃，也就是该返回-1。
如果R > n,就说明我们已经灌溉到了整个花园，记录安装的龙头数为res,每一轮加1，返回最后的结果即可。

### 代码

```python3
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        jumps= [-1] * (n+1)

        for i in range(0,n+1,1):
            d= ranges[i]
            if d == 0:
                continue
            left = 0 if i-d<0 else i -d
            right = i + d 
            jumps[left] = max(right,jumps[i]) 
        
        print(jumps)

        res = 0 
        lp = 0
        rp = 0
        while rp < n :
            R = -1
            for i in range(lp,rp+1,1):
                to = jumps[i]
                if to > rp:
                    R = max(to, R)
            if R == -1:
                return -1
            lp = rp
            rp = R
            res+=1
        return res
```