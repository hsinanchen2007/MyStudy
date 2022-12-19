### 解题思路
可以考虑一个数放入新数组里时候，应该会有三种情况：

1.放在数组首位`index[i] == 0` ：
    这时候就将该数字以数组形式 与原数组进行拼接
    `res = [nums[i]] + res`


2.放在数组末尾：
    当插入位置`index[i] >= len(nums)`，那就进行res尾部拼接：
    `res += [nums[i]]`
    这里也可以直接`res.append(nums[i])`


3.放在数组中间的i位置 ：
    比较一般的情况，对新数组进行切片，插入该元素
    `res = res[:index[i]] + [nums[i]] + res[index[i]:]`



时间复杂度o(N^2)：从头到尾遍历了数组 切片部分是o(N)的复杂度 （多谢集美指正）
空间复杂度o(N): 用到一个新数组进行存储

感觉空间复杂度上可以再进行一个优化
### 代码

```python
class Solution(object):
    def createTargetArray(self, nums, index):
        """
        :type nums: List[int]
        :type index: List[int]
        :rtype: List[int]
        """
        res = []
        for i in range(len(nums)) :
            # print res, nums[i],index[i]
            if index[i] == 0 :
                res = [nums[i]] + res
            elif index[i] >= len(nums) :
                res += [nums[i]]
            else : 
                res = res[:index[i]] + [nums[i]] + res[index[i]:]
        
        return res
```