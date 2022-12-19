### 解题思路
1. 遍历数组统计每个数字出现的次数,并记录在map 中
2. 对map.keys 进行排序 得到sortedKey数组
3. 遍历sortedKey 数组，
4. 假设当前key 的重复次数为n  则 当前key 所在的数字需要自增为   [key,key+1,......,key+n-1] 共需要 n*(n-1) 布
5. 我们令上一步 high=key+x-1   如果 high>= 当前的key  则 key 需要先自增到high+1【共需要(high+1-key)*map[key]】,然后再重复第4步
- 时间复杂度 O(max(Mlog(M),N)), 为不重复的数字总数，N 为数组总数，最差 Nlog(N)
- 空间复杂度  O(M)  最差O(N)

### 代码

```python
class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        map = {}
        count = 0
        for item in A:
            if map.get(item,0)==0:
                map[item] = 1
            else:
                map[item]=map[item]+1
        
        sortedKey = sorted(map.keys())
        ## 以及处理过的数据的最大值
        high=-1
        count=0
        for key in sortedKey:
            
            if(high>=key):
                count+=map[key]*(map[key]-1)//2
                count+=(high-key+1)*map[key]
                high=high+map[key]
            else:
                count+=map[key]*(map[key]-1)//2
                high=key+map[key]-1
        return count
```