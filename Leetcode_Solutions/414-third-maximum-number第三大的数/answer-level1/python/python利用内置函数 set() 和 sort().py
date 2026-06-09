### 解题思路
利用 set() 函数去重，再利用 sort() 函数排序。经过上述操作后，
若列表长度大于3，则输出第三大的数；
若长度小于3，则输出最大的数。

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        a = list(set(nums))
        a.sort()
        if len(a) < 3:
            return a[-1]
        else:
            return a[-3]



```