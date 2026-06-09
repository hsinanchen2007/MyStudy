### 解题思路1
暴力计算。
依次将数组中的2个值相加，看结果是否为目标值

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ret = []
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]== target:
                    ret.append(i)
                    ret.append(j)
                    return ret
```
### 结题思路2
利用字典
遍历数组nums,然后查看目标值和当前数组的差是否在字典中，在则返回数组下标和字典key值对应的value值，
否则把数组当前下标对应的值和数组下标放入字段中。这个解法速度快，**推荐**
### 代码
```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        k = len(nums)
        kv = dict()
        for i in range(0,k):
            temp = target - nums[i]
            if temp in kv:
                return [kv[temp],i]
            else:
                kv[nums[i]] = i
```