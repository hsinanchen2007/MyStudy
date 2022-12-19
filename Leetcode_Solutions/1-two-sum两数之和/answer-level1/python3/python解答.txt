### 解题思路
暴力破解是多次遍历列表找到符合要求的值。
通过建立值为key，索引为value的字典
如果tartar - 当前的值  能在hash字典中找到，就直接返回这两个索引。
不然就把当前值--索引对，加入字典。
主要是通过hash键值对加快遍历速度

### 代码

```python3
class Solution:
    def twoSum(self, nums,target):
        map = {}
        for index,value in enumerate(nums):
            if (target - value) in map:
                return [index, map[target - value]]
            else:
                map[value] = index

                        
            

```