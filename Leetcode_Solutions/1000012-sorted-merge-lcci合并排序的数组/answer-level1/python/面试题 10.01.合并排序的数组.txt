### 解题思路
执行时间优于89.29%提交，内存消耗优于100%提交
**算法流程**
1.对于B中每个元素b：
    2.对A进行遍历：
        若b < A[i],则将A[i]及其之后的元素向后移动一位，再令 A[i] = b,m + 1,改变对A进行的遍历范围（改变遍历的起点），返回到1
    3.若对A遍历结束时，没有找到符合条件的i使得b < A[i]：
        则将b直接至于A的末尾,对B中剩余的元素也全部置于A的尾部


### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        k = 0
        flag = False
        for b in B:
            q = 0
            if not flag:
                for i in range(k, m):
                    if b < A[i]:
                        q += 1
                        for j in range(m-1, i-1, -1):
                            A[j + 1] = A[j]
                        A[i] = b
                        m += 1
                        k = i + 1
                        break
            if not q:
                flag = True
                A[m] = b
                m += 1


```