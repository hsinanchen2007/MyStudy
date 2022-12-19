### 解题思路
由于每个区间列表都是成对不相交的，通过观察示例图像，我们可以发现相交的区间的low(设相交区间的区间为[low,high])为A，B两个区间列表中的max(A[i][0],B[j][0]),同理high为A，B两个区间列表中的min(A[i][1],B[j][1])。这样我们就可以设置两个指针i，j分别指向A，B两个区间列表，取low = max(A[i][0], B[j][0]),high = min(A[i][1], B[j][1]),如果 low <= high,则具有相交区间，否则根据A[i][1]，B[j][1]的关系，改变i，j的指针值，循环往复，直到遍历其中一个列表为止。

### 代码

```python3
class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        ans = []
        i = j = 0
        while i < len(A) and j < len(B):
            lo = max(A[i][0], B[j][0])
            hi = min(A[i][1], B[j][1])
            if lo <= hi:
                ans.append([lo, hi])
            if A[i][1] < B[j][1]:
                i += 1
            else:
                j += 1
        return ans

```