### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        #末尾双指针
        indexA = m-1
        indexB = n-1
        cur = m+n-1
        while(indexA>-1 and indexB>-1):#A,B均为越界
            if(A[indexA]>B[indexB]):#如果A的末尾元素大于B的末尾元素
                A[cur] = A[indexA]
                indexA-=1
                cur-=1
            else:
                A[cur] = B[indexB]
                indexB-=1
                cur-=1
        #如果B还有剩余，则将其全部放在A的前面即可
        if(indexB>-1):
            A[:indexB+1] = B[:indexB+1]

```