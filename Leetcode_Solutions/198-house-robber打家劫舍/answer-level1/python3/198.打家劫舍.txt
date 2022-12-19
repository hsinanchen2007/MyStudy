### 解题思路
- 设前k家人的最大金额为f(k),f(k)其实有两种组合
- 第一种，f(k)=f(k-1)，即不打劫第k家，前（k-1）金额最大即可，具体情况不管
- 第二种，f(k)=f(k-2)+Ak,即打劫了k家，这要求不能打劫第（k-1）家，即只能算f(k-2)再加上k家
- 到底选哪一种呢，f(k)=max(f(k-1),f(k-2)+Ak)
- 递归超时，所以用两个数字来存住两个状态，用于计算第三个状态。
- 然后更新两个数字。更新一次得到f(3),更新（k-2）次得到f(k)

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        L = len(nums)
        if L==0:return 0
        if L==1:return nums[0]
        if L==2:return max(nums[0],nums[1])
        first = nums[0]
        second = max(nums[1],nums[0])
        for k in range(2,len(nums)):
            first,second = second,max(first+nums[k],second)
        return second
```