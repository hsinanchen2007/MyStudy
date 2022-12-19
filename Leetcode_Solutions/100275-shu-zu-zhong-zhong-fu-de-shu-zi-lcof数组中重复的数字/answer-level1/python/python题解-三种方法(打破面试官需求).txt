### 排序做法
![image.png](https://pic.leetcode-cn.com/e8d30d2767296508c17bab953363ef7bf7303eb6d1d3351cf704f8a65ddd0394-image.png)

- 思路是将数组排好序,在查找重复数字,这个思路很简单
- 时间复杂度`O(nlogn)`,空间复杂度`O(1)`
 ### 代码

```python
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        pre = nums[0]
        for index in range(1, len(nums)):
            if pre == nums[index]:
                return pre
            pre = nums[index]
```


### 哈希表
![image.png](https://pic.leetcode-cn.com/98b344219a7d54ade893a5ed3e04c77665039dc1135005f9dda114d969781aa4-image.png)

- 遍历整个数组,当这个数字没有出现过哈希表的时候将其加入进去,如果在哈希表中则直接返回即可
- 时间复杂度`O(n)`,空间复杂度`O(n)`

### 代码

```python
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        dic = {}
        for i in nums:
            if i not in dic:
                dic[i] = 0
            else:
                return i
        
```
### 下标定位法
![image.png](https://pic.leetcode-cn.com/25c91ac83370d17649f41bf99e25484282aecfbf371815127e1f92a2bc1a9db5-image.png)

- 从头到尾扫描数组,当扫描到下标为`i`的数字时,首先比较这个数字(用`m`表示)是否等于下标`i`,如果等于就扫描下一个数字;如果不是,则将它和第`m`个数字进行比较.
- 如果它和第`m`个数相等,那么出现了重复直接返回;如果不相等,则将它和第`m`个数进行交换,把`m`放到第`m`个位置上
- 重复这个过程,知道出现一个重复的数字
- 时间复杂度`O(n)`,空间复杂度`O(1)`
### 代码
```
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i] != i:
                if nums[nums[i]] == nums[i]:
                    return nums[i]
                nums[nums[i]] , nums[i] = nums[i] , nums[nums[i]]
        
        return None

        
        
```
