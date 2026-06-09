### 解题思路
遍历一次，由于是排序列表，只需要一个变量x来对重复元素进行计数，x>2时删除当前元素
删除操作之后，当前位置之后的元素索引发生变化，通过变量y对删除操作计数，以抵消这种变化
![QQ图片20200115155449.png](https://pic.leetcode-cn.com/e37597b385a4a9c34fe7c683ba1cf7b26cf7e9006c727952c37f71efb9603bb0-QQ%E5%9B%BE%E7%89%8720200115155449.png)

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        x=1#用于重复元素计数
        y=0#用于删除操作次数计数
        lon=len(nums)
        for i in range(1,lon):
            if nums[i-y]==nums[i-1-y]:#与前一个元素对比
                x+=1#相同则x+1
                if x>2:
                    nums.pop(i-y)
                    y+=1#删除操作次数
            else:
                x=1#不同则x复位
        return len(nums)
```