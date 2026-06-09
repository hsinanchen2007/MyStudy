### 解题思路
1.设置指针idx1指向A的最后一个元素，指针idx2指向B最后一个元素
2.设置指针cur指向A的第m+n个元素。
3.比较idx1和idx2指向元素的大小，将大的元素移到cur处。
4.移动后滑动指针，将cur减1。若第三步中idx1对应的数据大，则将idx1减1，否则将idx2减1

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
        cur = m+n-1
        idx1 = m-1
        idx2 = n-1
        while idx1>=0 or idx2>=0:
            if idx1<0 or idx2<0:
                if idx1<0:
                    A[cur] = B[idx2]
                    idx2-=1
                    cur-=1
                else:
                    A[cur] = A[idx1]
                    idx1-=1
                    cur-=1
                continue
            if A[idx1]<=B[idx2]:
                A[cur] = B[idx2]
                idx2-=1
                cur-=1
            else:
                A[cur] = A[idx1]
                idx1-=1
                cur-=1
```