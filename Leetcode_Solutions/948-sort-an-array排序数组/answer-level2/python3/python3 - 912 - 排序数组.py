### 解题思路
+ 方法一：非考题时，python3可用`list.sort()`函数直接排序
+ 方法二：两次遍历将每一个数排到最小位置，时间复杂度$o(n^2)$，其中$n$为数组长度，超出时间限制
+ 方法三：计数排序，时间复杂度$o(n+k)$，其中$n$为数组长度，$k$为`max(nums)-min(nums)`，通过
    定义一个全0元素列表ans_tmp，长度为`max(nums)-min(nums)`
    遍历muns中每一个元素num，ans_tmp中对应位置`ans_tmp[num-min(nums)]`元素值+1
    遍历ans_tmp，组成结果数组，索引+min(nums)为元素值，元素值为元素个数

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        #方法一：开个玩笑哈哈哈
        ''' 
        nums.sort()
        return nums
        '''
        #方法二：这超时了
        ''' 
        for i in range(1, len(nums)):
            for j in range(i, 0, -1):
                if nums[j] < nums[j-1]:
                    nums[j], nums[j-1] = nums[j-1], nums[j]
                else:
                    break
        return nums
        '''
        #方法三：计数排序
        ans = []
        n = len(nums)
        max_ = max(nums)
        min_ = min(nums)
        ans_tmp = [0] * (max_ - min_ + 1)
        for tmp in nums:
            ans_tmp[tmp - min_] += 1
        for i in range(len(ans_tmp)):
            ans += [i+min_] * ans_tmp[i]
        return ans
                
```