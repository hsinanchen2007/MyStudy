### 解题思路
先将待排序list按第一个数据排序，下一步逐步规划。如果发生合并则将合并的作为pre，否则将将cur作为pre。


![634657b1b30d89932eb1be4da8d22ab.png](https://pic.leetcode-cn.com/7069f8fc5d4ee7453efbb7e47076fa3a86c9bdba0e8a36c2ac01cc5ae8a9a08e-634657b1b30d89932eb1be4da8d22ab.png)

### 代码

```python3
class Solution:
    def merge(self, intervals):
        ans=[]
        intervals.sort()
        n=len(intervals)
        if n==0:
            return []
        if n==1:
            return intervals
        i=1
        pre=intervals[i-1]
        cur=intervals[i]
        while i<n:
            if pre[0]<=cur[0]<=pre[1] or pre[0]<=cur[1]<=pre[1]:
                low=min(pre[0],cur[0])
                hid=max(pre[1],cur[1])
                pre=[low,hid]
                i+=1
                if i==n:
                    ans.append(pre)
                else:
                    cur=intervals[i]
            else:
                ans.append(pre)
                i+=1
                pre=cur
                if i<n:
                    cur=intervals[i]
                else:
                    ans.append(pre)
        return ans
```