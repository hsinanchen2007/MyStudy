公式法：统计不重复升序数字对的个数，然后用k*(k-1)/2的公式累加起来。

![image.png](https://pic.leetcode-cn.com/30d83092c68c12008b65721284ccda02aa143750fb4e5c6fc6c0dbb1f424fa16-image.png)

```
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        ans=0
        d=collections.defaultdict(int)        
        for i,j in dominoes:
            if i>j:
                i,j=j,i
            d[(i,j)]+=1
        for k in d.values():
            ans+=k*(k-1)//2
        return ans
```



实时累加法：统计正反两个方向数字对的个数，如果之前出现过这个数字对，那总数就加上这个数字对的个数。

![image.png](https://pic.leetcode-cn.com/aa0d9b2df06d67bff7c5f48fb03de073e9cd44cc3d0660723c5bef6aa89150fd-image.png)

```
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        ans=0
        d=collections.defaultdict(int)
        for i,j in dominoes:
            if (i,j) in d:
                ans+=d[(i,j)]
            d[(i,j)]+=1
            if i!=j:
                d[(j,i)]+=1
        return ans
```
