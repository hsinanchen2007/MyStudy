### 解题思路

# 双指针从后往前扫描，最大的数添加到末尾
### 代码
**方法 1：逆向双指针**

![截屏2020-03-03上午10.41.47.png](https://pic.leetcode-cn.com/88b951f82a7ad19bc9fd719ccef529cd4ac7e2fa165f8c7214519263e12413aa-%E6%88%AA%E5%B1%8F2020-03-03%E4%B8%8A%E5%8D%8810.41.47.png){:width=400}

```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa, pb = m-1, n-1
        tail = m+n-1
        while 0 <= pa or 0 <= pb: #至少有一个list还有数组未扫描完
            if pa == -1:    #A已扫描完成，B[pb]是最后一位未扫描的元素
                A[tail] = B[pb]
                pb -= 1
            elif pb == -1:
                A[tail] = A[pa]
                pa -= 1
            elif A[pa] < B[pb]:
                A[tail] = B[pb]
                pb -= 1
            else:
                A[tail] = A[pa]
                pa -= 1
            tail -= 1
```
**方法 2: 双指针**

![截屏2020-03-03上午10.37.50.png](https://pic.leetcode-cn.com/66b53b1842f3952f3cc475c8501ce6fc6093facc7bff60803bd0200d8870c502-%E6%88%AA%E5%B1%8F2020-03-03%E4%B8%8A%E5%8D%8810.37.50.png){:width=400}

```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        sorted = []
        pa, pb = 0, 0
        while pa < m or pb < n:
            if pa == m:
                sorted.append(B[pb])
                pb += 1
            elif pb == n:
                sorted.append(A[pa])
                pa += 1
            elif A[pa] < B[pb]:
                sorted.append(A[pa])
                pa += 1
            else:
                sorted.append(B[pb])
                pb += 1
        A[:] = sorted
```
**方法 3: 直接合并后排序**

![截屏2020-03-03上午10.36.34.png](https://pic.leetcode-cn.com/f00e0d6ef7b6cfa393ae4b2f2967dec389d8c6bc2ea8782478e38bb65cda2860-%E6%88%AA%E5%B1%8F2020-03-03%E4%B8%8A%E5%8D%8810.36.34.png){:width=400}
```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        A[m:] = B
        A.sort()
```