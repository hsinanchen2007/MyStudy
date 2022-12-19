### 解题思路
此处撰写解题思路
指针设置为从后向前遍历，每次取两者之中的较大者放入A的递减尾部
当pa或者pb为-1时，另一组的剩余元素都放入A

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa,pb = m-1, n-1
        tail = m+n-1
        while pa>=0 or pb>=0:
            if pa==-1:
                A[:tail+1] = B[:pb+1]
                pb = -1
            elif pb==-1:
                A[:tail+1] = A[:pa+1]
                pa = -1 
            elif A[pa]>=B[pb]:
                A[tail] = A[pa]
                pa -=1
            else:
                A[tail] = B[pb]
                pb -=1
            tail -=1
             
```