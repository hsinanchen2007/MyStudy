### 解题思路
开始的代码总是超时，感觉代码没问题，就加了一些限制条件，结果还是不行。
后来明白是求和，因为开始的代码在每次窗口移动时都进行一次sum求和，导致用时很长。
改进方法是每次移动窗口，在原有的子数组和的基础上减去被移走的数并加上新增加的数。

### 代码

```python3
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        count = 0
        for i in range(len(arr)-k+1):
            if i == 0:
                sum_arr = sum(arr[i:i+k])
            else:
                sum_arr = sum_arr-arr[i-1]+arr[i+k-1]
            if sum_arr>=threshold*k:
                count += 1
        return count

```