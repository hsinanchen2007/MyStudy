### 解题思路
Python小白，初学，折腾语法用了好久。
尽量记录我所能想到的最优写法，萌新一个，如果有大佬路过请指教。

分析：本质是查找，时空复杂度均集中在nums[j]的查找过程中
方法一：
遍历算法，也就是暴力枚举。
时间复杂度O(n^2)
空间复杂度O(n)
输入必有解，则只可能有两种情况：
1、target-nums[i]有2个元素，一个是nums[i]，另一个是nums[j]
2、target-nums[i]有1个元素，是nums[j]
两种情况合并，即为：
target-nums[i]在nums[i+1:]中


### 代码

```python3

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            if target-nums[i] in nums[i+1:] :
                return [i,nums.index(num,i+1)]
```

### 解题思路
方法二：
哈希算法
时间复杂度O(n)
空间复杂度O(n)，最差为O(n^2)

#list转化为dictionary：
1、通过zip函数
2、通过循环
3、通过enumerate函数

#依然保留方法一中nums[i]和nums[j]在不同子串的思路
1、在一次循环中，查找和存入字典一起完成
2、遍历的是nums[j]，在字典中向前查询nums[i]

### 代码

```python3

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict={}
        for j,num in enumerate(nums):
            i=dict.get(target-num)
            if i is not None:
                return [i,j]
            dict[num]=j
```