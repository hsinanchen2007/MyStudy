### 解题思路
主要思路：  
有序数组，比较A,B末尾的数字，较大的放入A末尾的空间。  
时间复杂度：  
只有一个for循环，长度为k = m+n，因此时间复杂度为O(k)  
主要注意事项：  
m和n的取值必须要在比大小之前判断，当值为0时，说明该数组已经全部排完，因此需要将另一数组的指针前移。  
### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        k = m+n
        for i in range(k):
            if m == 0:
                max_num = B[n-1]
                n -= 1
            elif n == 0:
                max_num = A[m-1]
                m -= 1
            elif A[m-1]>=B[n-1]:
                max_num = A[m-1]
                m -= 1
            elif A[m-1] < B[n-1]:
                max_num = B[n-1]
                n -= 1
            A[k-1-i] = max_num
```