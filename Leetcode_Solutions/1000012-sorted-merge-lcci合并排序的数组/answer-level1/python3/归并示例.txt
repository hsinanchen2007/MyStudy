### 解题思路
有两个数组A和B，已经给出的输出有A的元素个数和B的元素个数，并且A有足够空余空间容纳B；
所以定义两个变量i和j，初始都指向A和B的第0个元素，然后开始遍历两个数组的公共部分，如果i指向的值小，就先将i所指向的值放入临时数组temp中，然后让i指向下一个值，如果j指向的值小，就将j指向的值放入临时数组中，然后让j指向下一个值，依次类推，直到两个数组的公共部分被遍历完，最后用两个循环将元素个数较多的数组的剩余的值直接添加在临时数组temp中即可，最后将temp中的值放回A数组中，即可。是一个简单的归并过程。

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        temp = []
        i = 0
        j = 0
        while i < m and j < n:
            if A[i] <= B[j]:
                temp.append(A[i])
                i += 1
            if A[i] > B[j]:
                temp.append(B[j])
                j += 1
        while i < m:
            temp.append(A[i])
            i += 1
        while j < n:
            temp.append(B[j])
            j += 1
        i = 0
        for j in temp:
            A[i] = j
            i += 1
```