### 解题思路
选择一点为基准，遍历其他所有点，计算两点间距离，并将距离相等的点个数作为哈希表的值存储
根据点个数依照排列组合规律计算出结果

时间复杂度：O(n^2)
空间复杂度：O(n)

### 代码

```python3
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        res=0
        for i in range(len(points)):
            hashmap={}
            for j in range(len(points)):
                if j==i:
                    continue
                d=self.distance(points[i],points[j])
                if d not in hashmap:
                    hashmap[d]=1
                else:
                    hashmap[d]+=1
            for v in hashmap.values():
                res+=v*(v-1)
        return res
            
    def distance(self,x,y):
        return math.sqrt((x[0]-y[0])**2+(x[1]-y[1])**2)
```