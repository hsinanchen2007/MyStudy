### 解题思路
+ 要么计算 B[j]加入C时构成了多少逆序对
+ 要么计算 A[i] 加入C时构成多少逆序对，不要重复计算

看 liweiwei 大佬的题解，另一个解法是树状数组，但是这个还没有深入理解，有待进一步学习。


### 代码

```python3
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        ## 归并排序的一个用处
        def merge(A, B):
            n1, n2 = len(A), len(B)
            i, j = 0, 0
            C = []
            count = 0
            while i<n1 and j<n2:
                if A[i] <= B[j]:
                    C.append(A[i])
                    i += 1
                else:
                    C.append(B[j]) #要么计算 B[j]加入C的时候构成了多少逆序对，要么计算 A[i] 加入时构成多少逆序对，不要重复计算
                    count += (n1-i)
                    j += 1
            if i < n1:
                # count += (n1-i)*n2  # 重复计算了
                C += A[i:]
            if j < n2:
                C += B[j:]
            return C, count

        def mergesort(nums, left, right):
            if left >= right:
                return nums[left:right+1], 0
            mid = left + (right-left)//2
            A, n1 = mergesort(nums, left, mid)
            B, n2 = mergesort(nums, mid+1, right)
            C, n3 = merge(A, B)
            return C, n1+n2+n3

        A, res = mergesort(nums, 0, len(nums)-1)
        return res
```