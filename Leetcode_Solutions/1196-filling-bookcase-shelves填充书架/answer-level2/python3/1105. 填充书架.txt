思路：
1. 将第i本书当做最后一本书，我们需要求i本书的最小高度f[i]。
2. 所以如果最后一本书放到新的一层中，f[i] = f[i-1]+books[i-1][1]
3. 最后一本书也可以和他前一本书一同放到新的一层。这时：f[i] = f[i-2] + max(books[i-1][1]，books[i-2][1])
4. 这时我们应该考虑最后一本书一共和它的前面几本书放到新的一层呢？这样就可以采用试探来做，试探的终止条件就是前面没有书了或者是当前层的宽度超出了最大宽度。记录这个过程中最小的f[i]
5. 状态转移方程：**f[i] = min(f[j-1] + cur_height)**，cur_height表示当前最后一层的最高的那本书，j需要从i遍历到0
6. 初始条件f[0] = 0,一本书都没有最小高度肯定是0；计算顺序i从小到大。
7. 时间复杂度O(N^2),空间复杂度O(N)

```python
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        import sys
        n = len(books)
        f = [sys.maxsize]*(n+1)
        f[0] = 0
        for i in range(1,n+1):
            cur_height = 0 #以第i本书作为最后一本书，最后一层的高度
            cur_weight = 0 #以第i本书作为最后一本书，最后一层的宽度
            for j in range(i,0,-1):
                cur_height = max(cur_height,books[j-1][1])
                cur_weight += books[j-1][0]
                if(cur_weight>shelf_width):
                    break
                f[i] = min(f[i],f[j-1] + cur_height)
        return f[-1]
```