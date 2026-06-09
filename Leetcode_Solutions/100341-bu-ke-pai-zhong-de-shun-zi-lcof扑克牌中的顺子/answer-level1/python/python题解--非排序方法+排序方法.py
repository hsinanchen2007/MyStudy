### 非排序方法
![image.png](https://pic.leetcode-cn.com/c79a5e496dbdc6cc68b62ce96bfccbe644c960f97ca9e7ed9ec584f039a2f38d-image.png)

- 我们先看一个没有重复元素且连续的数组,数组中最大元素为`m`,数组中最小元素为`n`,怎么样知道这个数组中有多少个数,就是`m-n+1`
- 再看我们的题目也是要求抽取出来的5张牌是连续的,所以我们可以以`m-n+1 <= 5`来判断是否能组成连续的序列
- 但这里面又说到大小王可以充当任意的数字,且为了符合要求不能出现重复的数字
- 我们统计数组中最大值和最小值的时候不需要统计大小王`0`的,需要统计下是否出现了重复的数字,如果有重复数字出现说明不满足条件
- 时间复杂度`O(n)`,空间复杂度`O(n)`
### 代码

```python
class Solution(object):
    def isStraight(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        min_ = 14
        max_ = 0
        overlapNumber = [0] * 15 #记录有无重复元素出现
        for i in range(5):
            if nums[i] == 0:# 遇到大小王则跳过
                continue
            if overlapNumber[nums[i]]:#存在重复元素则不符合条件
                return False
            overlapNumber[nums[i]] = 1 #记录已经出现过的元素
            min_ = min(min_, nums[i])# 更新最小值
            max_ = max(max_, nums[i])# 更新最大值
        return max_ - min_ + 1 <= 5 #判断
```
### 2.排序法
![image.png](https://pic.leetcode-cn.com/3f61c996c5299f8ff668d4205b425bb9b96db25e2d72e3cd0e907930cbb72556-image.png)

- 题目要求我们判断抽取的数字是否有序,那么是不是先将抽取的数字排序在看看有序是不是方便点,let's try!!
- 先将数组进行排序,开始遍历数组,在此过程中需要统计大小王`0`的个数,设置两个指针`low`,`high`分别指向相邻的两个元素
1. 当后面指针`low`遇到`0`时,`num_0 += 1`
2. 当`low`指向的不是`0`时,这时候需要判断是否出现了重复的元素,即`low`和`high`指向的是否为同一个数字.如果指向同一数字,直接返回`False`,否则判断两数的差值减1是否大于`nums_0`,如果大于说明即使用`0`填充也不能组成连续的序列,返回`False`,若果小于的话,就将`0`填充到这,并更新`num_0`的个数
3. 循环一次后,将两个指针分别向前移动一位
- 时间复杂度`O(n)`,空间复杂度`O(1)`
### 代码
```
class Solution(object):
    def isStraight(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums.sort()#排序
        num_0 = 0
        low = 0
        high = 1
        while high < 5:
            if nums[low] == 0:#如果遇到0,更新num_0
                num_0 += 1
            elif nums[low] == nums[high]:#如果遇到重复元素,返回False
                return False
            else:
                temp = nums[high] - nums[low]
                if temp - 1 > num_0: #如果0的个数不足以填充,返回False
                    return False
                else:# 否则更新num_0
                    num_0 -= (temp - 1)
            #指针后移
            low += 1
            high += 1
        return True
```
