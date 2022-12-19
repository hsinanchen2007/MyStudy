### 解题思路
先排序，然后从最小值开始变。

如果存在 <0 的值，则依次变化。
如果不存在 <0的值了，则看剩余的变化次数是奇数还是偶数，如果是偶数，则可以变换回原序列，直接返回求和即可。如果是奇数，则只能将最小值变换为负值。

### 代码

```python3
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        A.sort()
        change_times = 0
        
        while A[change_times] < 0:
            A[change_times] *= -1
            change_times += 1
            if change_times >= K: 
                break

        return sum(A) - min(A)*2 if (K - change_times)%2 else sum(A)

            

```