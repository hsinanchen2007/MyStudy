### 解题思路
需要注意的是特殊情况：k=0 or len(arr)==0 or len(arr)==1
按照快速排序，找出分割点位置，左边都比分割点小，右边都比分割点大，将分割点和k比较，选择递归执行的部分，省去另一部分的执行时间
终止条件：分割点base == k-1，返回前k个元素arr[:k]

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not len(arr) or not k:
            return None
        if len(arr)==1:
            return arr
        
        def division(arr, left, right):
            base = arr[left]
            while left<right:
                while left<right and arr[right]>=base:
                    right -= 1
                arr[left] = arr[right]
                while left<right and arr[left]<=base:
                    left += 1
                arr[right] = arr[left]
            arr[left] = base
            return left

        def func(arr, left, right, k):
            base = division(arr, left, right)
            if base == k-1:
                return arr[:k]
            elif base <k-1:
                ans = func(arr, base+1, right, k)
                return ans
            else:
                ans = func(arr, left, base-1, k)
                return ans
        return func(arr, 0, len(arr)-1, k)
            

```