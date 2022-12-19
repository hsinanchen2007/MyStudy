### 解题思路
**目标：**
- 空间复杂度O(1) ：原地修改，不使用辅助空间
- 时间复杂度O(m+n)

比较大小肯定需要双指针。

但是如果还像归并排序（使用辅助数组）那样从前向后比较，那么可能覆盖掉A原有的值。

使用插入排序的复杂度又是O(nm). 遍历B:O(n) 插入A中一次O(m)

不妨换个思路：从后向前比较，从后向前覆盖。

**注意：**
- B中元素用完后可以直接结束，因为A剩下的元素不用动了。
- A中元素用完后，要记得把B剩下的元素放进去。

**think twice code once**

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        p = m+n-1
        m-=1
        n-=1
        while n>=0 and m>=0:
            # print(p,m,n)
            if A[m] > B[n]:
                A[p] = A[m]
                m-=1
                
            else:
                
                A[p] = B[n]
                n-=1

            p-=1
        while n>=0:
            A[p] = B[n]
            n-=1
            p-=1
        

```