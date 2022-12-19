### 解题思路
开始为twoSum(nums,target):
这里报错TypeError:drive() takes 2 positional argument but 3 were given

排查：
这里是SELF参数的问题，self 表示创建的类实例本身，方法内部就可以把各种属性绑定到self，因为self就指向创建的实例的本身。

### 代码

```python3
class Solution:
    def twoSum(self,nums,target):
        lens = len (nums)
        j=-1
        for i in range(lens):
            if (target-nums[i]) in nums:
                if (nums.count(target-nums[i])==1)&(target-nums[i]==nums[i]):
                    continue
                else:
                    j = nums.index(target-nums[i],i+1)
                    break
        if j>0:
            return[i,j]
        else:
            return[]
```