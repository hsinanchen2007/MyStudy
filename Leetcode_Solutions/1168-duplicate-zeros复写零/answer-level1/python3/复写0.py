![复写0.png](https://pic.leetcode-cn.com/bdbd067b9d3e882f19211aa6681220139fcf831f84c084afcb2667a3e5a46355-%E5%A4%8D%E5%86%990.png)

### 解题思路
首先，找到值为0的元素的下标位置并记录之。
然后，在这些位置插入0，并在插入0之后移除最后一个元素。考虑到插入j个0后原下标后移j,因此新的下标位置pos应为原下标位置加j。

### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        indexs = []
        n = len(arr)

        i = 0
        while i < n:
            if arr[i] == 0:
                indexs.append(i)
            i += 1
        
        m = len(indexs)
        j = 0
        while j < m:
            pos = j + indexs[j]
            if pos >= n:
                break
            arr.insert(pos, 0)
            arr.pop()
            j += 1
        
```