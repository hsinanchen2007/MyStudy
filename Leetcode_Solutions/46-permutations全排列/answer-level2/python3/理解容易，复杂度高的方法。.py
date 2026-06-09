### 解题思路
我的这种方法双标复杂度真的都好高，但是就是把所有的组合对写出来，包括重复的（一个元素可能重复3次也可能重复2次），不管，去重就好了，只要列表长度变短，专门找长度不变的列表即可。（这里由于python3 set集合去重后会改变次级列表里面数字的排序，所有写了个tmp_copy，最后根据下边索引找到原先的满足题意的排列组合。）

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        tmp = ['']
        nums = [*map(str,nums)]
        result = []
        for i in range(len(nums)):
            tmp = [x +','+ y for x in tmp for y in nums]
        tmp = [*map(lambda x:x.split(','),tmp)]
        tmp_copy = tmp
        tmp = [*map(set,tmp)]
        tmp = [*map(list,tmp)]
        for i in range(len(tmp)):
            tmp[i].pop(0)
            if len(tmp[i])==(len(nums)):
                tmp_copy[i].pop(0)
                tmp_copy[i] = [*map(int,tmp_copy[i])]
                result.append(tmp_copy[i])
        return result
```