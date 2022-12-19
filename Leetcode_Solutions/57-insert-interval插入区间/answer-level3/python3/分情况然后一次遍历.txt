思路：总的来说，分为newinterval插入首部和不插入首部两种情况，然后不插入首部又细分为3种情况。请看注释

```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        n = len(intervals)
        m = len(newInterval)
        if n == 0 or m == 0: return [intervals+newInterval]
        
        def calcu_Overlapping(index_1, index_2):
            nonlocal res
            for j in range(index_1,index_2):  
                if res[-1][1] >= intervals[j][0]:  # 计算newInterval和intervals中有重叠的部分
                    res[-1][1] = max(res[-1][1], intervals[j][1])
                else:  # 一旦没有重叠了，直接退出
                    res += intervals[j:]
                    break
                    
        if intervals[0][0] > newInterval[0]:  # newInterval插入到intervals的首部
            res.append(newInterval)
            calcu_Overlapping(0,n)  # 计算重叠
            
        else:  # newInterval不插入到intervals的首部
            for i in range(n):
                if intervals[i][1] >= newInterval[0]:  # 该条件包含了5种情况中的4种,如[2, 4]和[0, 1]、[2, 4]和[0, 2]、[2, 4]和[3, 3.5]、[2, 4]和[4, 5]
                    if intervals[i][0] > newInterval[1]:  # 该条件是为了解决上4种情况中的[2, 4]和[0, 1]，因为没有重叠所以直接合并一下
                        res += intervals[:i]
                        res.append(newInterval)
                        res += intervals[i:]
                        break
                    else:  # 另外3中情况，有重叠
                        res += intervals[:i+1]
                        res[-1][0] = min(res[-1][0], newInterval[0])
                        res[-1][1] = max(res[-1][1], newInterval[1])
                        calcu_Overlapping(i+1, n)
                        break
                else:  # 5种情况中的最后一种，newInterval插入到intervals的尾部，没重叠，如[2, 4]和[5, 6]
                    if i == n-1:
                        res += intervals[:i+1]
                        res.append(newInterval)
        return res
```
