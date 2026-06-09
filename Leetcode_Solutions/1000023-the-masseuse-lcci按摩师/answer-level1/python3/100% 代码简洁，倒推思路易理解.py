### 解题思路
对于任意一个包含n个元素的预约集合[N1,N2,…,Nn-2,Nn-1,Nn]，返回的总分钟数最大值有两种可能，一种是前n-1个元素[N1,N2,…,Nn-2,Nn-1]返回的总分钟数较大，[Nn]较小，如[1,2,3,4,5,6,1],此时n个元素返回的总分钟数即为前n-1个元素返回的总分钟数，对应程序中的nmax1；另一种情况相反，[Nn]相对较大，此时n个元素返回的总分钟数为前n-2个元素返回的总分钟数与[Nn]的和，对应程序中的nmax2+nums[i]。因此，对于任意一个包含n个元素的预约集合[N1,N2,…,Nn-2,Nn-1,Nn]，返回的总分钟数最大值一定是nmax1和nmax2+nums[i]中的较大者。
这个思路可以从第一个元素开始迭代计算出最后的最大值。

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        nmax1 = nmax2 = 0
        i = 0
        while i < len(nums):
            nmax1 , nmax2 = max(nmax1,nmax2+nums[i]) , nmax1
            i +=1
        return max(nmax1 , nmax2)
```