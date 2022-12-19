### 解题思路
第一步先将所给数组按从小到大排序存入临时数组中，查询原数组中的数在排序后数组中的索引值即可。
此外当原始数组中若存在相同的数时，可以利用index方法巧妙解决。
由于通过index方法返回的索引下标为第一此出现的位置，故不用考虑数组中有重复的数。
为了优化程序的运行时间，故采用列表推导。
详细解释可以看我在百度经验发表的文章，文章地址：https://jingyan.baidu.com/article/6525d4b112bc30ed7c2e946f.html

### 代码

```python3  
原始代码
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        result = []
        temp = nums[::1]
        temp.sort()
        i = 0 
        while  i < len(nums):
            result.append(temp.index(nums[i]))
            i += 1
        return result
经过优化后的代码
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        temp = nums[::1]
        temp.sort()
return [temp.index(i))  for i in nums]
```