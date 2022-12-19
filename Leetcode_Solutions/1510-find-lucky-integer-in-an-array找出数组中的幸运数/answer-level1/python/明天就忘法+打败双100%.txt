### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        n=len(arr)
        if not arr or n<0:
            return -1
        dist={}
        #统计每个数字的出现的次数，字典保存
        for i in arr:
            dist[i]=arr.count(i)
        #字典key 和value 相等的进入比较maxs
        maxs=float("-inf")
        for a in dist.items():
            if a[0]==a[1]:
                if a[0]>maxs:
                    maxs=a[0]
        return -1 if maxs==float("-inf") else maxs
```