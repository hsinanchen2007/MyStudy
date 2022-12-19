### 解题思路
首先计算出数组的和，如果不能整除 3, 由于是整数数组，则必然不能分为三部分。
设能够整除 3， 计算 target = all_sum //3

从左到右遍历找到第一个 i, 使得 sum(A[:i]) = target, 如果 i 不存在，或者 i>n-3, 都不满足。

如果有更大的 i2 使得 sum(A[:i2]) = target, 则说明 sum(A[i+1:i2]) = 0, 这丝毫不影响，因为和为 0 的这一段既可以合并第一部分，也可以合并到第二部分。

从右到左遍历找到第一个 j, 使得 sum(A[j:]) = target, 如果 j 不存在，或者 j <= i+1, 都不满足。

注意到，这里用 for 循环找，找到了就 break, 循环结束后，需要 check 一下，是否是真的找到了，而不是仅仅到了循环终止条件。

光有 target = all_sum//3 不去 check  i+1<j 可能会犯错。因为 sum(A) = 3*target, sum(A[:i]) = target, sum(A[j:]) = target, 并不能保证一定有一个 A[i+1:j] 使得其非空，且 sum(A[i+1:j]) = target. 

例如总和为 0,  [1,-1, 1,-1], i=1, j=2, 但犯错。


### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        n = len(A)
        all_sum = sum(A)
        if all_sum % 3 != 0:
            return False
        target = all_sum //3
        
        cum_val = 0
        for i in range(n):
            cum_val += A[i]
            if cum_val == target:
                break
        if (cum_val != target) or i> n-3:
            return False
        
        cum_val = 0
        for j in range(n-1, i, -1):  # 这里也可以取 i-1，中间至少要空一个数
            cum_val += A[j]
            if cum_val == target:
                break
        if (cum_val == target) and i+1 < j:   # [1,-1,-1,1] 小心 0/3 = 0
            return True
        else:
            return False
```