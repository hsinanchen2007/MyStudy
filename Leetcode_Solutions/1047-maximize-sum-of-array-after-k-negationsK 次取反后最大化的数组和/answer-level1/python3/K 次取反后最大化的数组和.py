### 解题思路
代码中已经注释了。
时间:o(nlogn)
空间:o(logn)

### 代码

```python
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        # 先降序
        A.sort(reverse=True)
        # 用于记录最后需要转换的最小值，只有最小值影响才最小
        current = 0
        # 从后往前遍历
        for i in range(len(A)-1, -1, -1):
            if A[i] < 0 and K > 0: # 小于0且k>0 从后往前一直取反
                A[i] = -A[i]
                K -= 1

            elif A[i] > 0 and K > 0: # 遇到>0且K>0时,进行判断后得到最终的下标
                if i == len(A)-1:
                    current = i
                    break
                else:
                    if A[i] > abs(A[i+1]):
                        current = i+1
                    else:
                        current = i
                    break
            else: # 其它情况直接取下标
                current = i
                break
        # 最小值的取反只要0次或1次
        K = K % 2 
        if K:
            A[current] = -A[current]
        # 求和
        sums = 0
        for x in A:
            sums += x
        return sums
```