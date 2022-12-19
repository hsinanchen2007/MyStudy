### 解题思路
居然击败了很多人？
![image.png](https://pic.leetcode-cn.com/39283da091b9b370e7c3e49b29673690142ebd0a5c28771fc0dd7d57c5dbb527-image.png)

### 代码

```python3
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        res = []   # 不能用字典，后面出现相同次数1的，会把前面的替换掉，会缺失信息
        for i in range(len(mat)):  # 统计1个个数
            ones = mat[i].count(1)
            res.append((ones, i))

        res.sort(key=lambda x:x[0]) # 按照1的个数从小到大排序，1少的更弱

        ans = []
        for i in range(k):  # 取前k个
            ans.append(res[i][1])
        return ans

# >>> list=[('b',6),('a',1),('c',3),('d',4)]
# >>> list.sort(key=lambda x:x[1])
```