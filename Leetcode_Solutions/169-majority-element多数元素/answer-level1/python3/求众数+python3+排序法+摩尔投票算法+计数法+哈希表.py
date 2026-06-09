### 解法1：排序法
众数是出现次数超过一半的数，所以排序后中间的数就是众数，代码如下：
```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums)//2]
```
### 解法2：摩尔投票算法
这个方法如果要详细的去理解，很麻烦，也分很多种情况。

其核心思想就是：**抵消**

最差的情况就是其他所有的数都跟众数做了抵消，但是由于众数出现的次数大于1/2，所以最终剩下的还是众数。

```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 1
        target = nums[0]
        n = len(nums)
        for i in range(1,n):
            if nums[i] == target:
                count += 1
            else:
                if count >= 1:
                    count -= 1
                else:
                    target = nums[i]
                    
        return target
```
### 解法3：计数法
先set求集合，后判断集合中的数是否在数组中出现了一半的次数
```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        set1 = set(nums)
        for i in set1:
            if nums.count(i) > (len(nums)//2):
                return i
                    
```
### 解法4：哈希表
```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = {}
        set1 = set(nums)
        for i in nums:
            dic[i] = dic.get(i,0) + 1
        for i in set1:
            if dic.get(i)>(len(nums)//2):
                return i
```
