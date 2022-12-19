### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        '''
        找在数组中出现次数大于n/2的元素
        暴力：
            开辟一个数组，下标为i的元素存储i在原数组中出现的次数
            要创建数组需要遍历nums找到最大值
            意料之中的超出内存限制
        
        '''
        # maxnum = 0
        # for num in nums:
        #     if num > maxnum:
        #         maxnum = num
        # arr = [0 for x in range(maxnum+1)]
        # for num in nums:
        #     arr[num] += 1
        
        # for i in range(len(arr)):
        #     if arr[i] > len(nums)//2:
        #         return i
        '''
        找在数组中出现次数大于n/2的元素
        暴力：
            开辟一个字典，键为i的元素存储i在原数组中出现的次数
            要创建数组需要遍历nums找到最大值
        '''
        d = {}
        for num in nums:
            if num in list(d.keys()):
                d[num] += 1
            else:
                d[num] = 1
        for x in d:
            if d[x] > len(nums)//2:
                return x
```