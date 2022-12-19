```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        #初始化一个全0数组
        hash = [0]*10000

        #将所有区间内的值标为1 除了最后一位 如[3,4]只标记3 是为了防止[3,4]和[5,6]区间合并，时间O(n2)
        for i in range(len(intervals)):
            for j in range(intervals[i][0],intervals[i][1]):
                hash[j] = 1
        
        L = 0
        R = 0
        res = []
        #读取所有剩余区间 O(n)
        while R < len(hash)-1:
            if hash[R] == 1:
                L = R 
                while R + 1 < len(hash) and hash[R+1] == 1:
                    R += 1
                res.append([L,R+1])
            R += 1
        
        #注意还有大量[3,3]这样的区间，甚至会重复出现，需要额外添加
        for i in range(len(intervals)):
            if intervals[i][0] == intervals[i][1] and (hash[intervals[i][0]] == 0  and hash[intervals[i][0]-1] == 0) :
                if intervals[i] not in res:
                    res.append(intervals[i])

        return res
```