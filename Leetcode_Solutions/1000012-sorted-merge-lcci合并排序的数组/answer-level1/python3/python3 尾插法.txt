### 解题思路
利用数组B已经排序好，且A的尾部空间足够的条件，按照从大到小的顺序尾插。
误区提示：一定要注意if语句的先后顺序，由于python中A[-1]指的是取数组A的最后一个元素。所以判断数组下标是否=-1要放在前面。
### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        ta, tb = m - 1, n - 1
        tail = m + n - 1
        while ta >= 0 or tb >= 0:
            if ta == -1:
                A[tail] = B[tb]
                tb -=1
            elif tb == -1:
                A[tail] = A[ta]
                ta -= 1
            elif A[ta] <= B[tb]:
                A[tail] = B[tb]
                tb -= 1
            else:
                A[tail] = A[ta]
                ta -=1
            tail -= 1

```