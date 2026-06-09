将原数组各元素值和索引记录在字典中，遍历靠左的人，右边不是他的对象则调换位置，再更新字典中人的索引即可。
```
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        def find(n):
            if n % 2 == 0:
                return n + 1
            return n - 1
        
        l = len(row)
        hashMap = {}
        ans = 0
        for i, j in enumerate(row):
            hashMap[j] = i
        for i in range(0, l-2, 2):
            p1 = row[i]
            p2 = find(p1)
            if row[i+1] != p2:
                t = row[i+1]
                row[i+1], row[hashMap[p2]] = row[hashMap[p2]], row[i+1]
                hashMap[t], hashMap[p2] = hashMap[p2], hashMap[t]
                ans += 1
        return ans
```
