### 题目：
求一个列表 [1,3,5,7,8,9] 中，相加之和为 12 的两个值的索引

### 1，最简单的暴力破解，两遍循环，O(n²)O(1)，6292 ms，14.3 MB

```Python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i,v in enumerate(nums[:-1]):
            for ii, vv in enumerate(nums[i+1:]):
                if v+vv == target:
                    return [i, ii+i+1]
```

### 2，用减法寻找，而非加法验证，O(n²)O(1)，844 ms，14.4 MB
看似减少了算法复杂度，实际上只是把第二层的遍历交给了内置函数
问题：注意 [3,3]=6 这种情况，如果只是简单的利用 index 去找，很可能找到的是自己
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i,v in enumerate(nums[:-1]):
            search = target-v
            if search in nums[i+1:]:
                return [i, nums[i+1:].index(search)+i+1]
```


### 3，两遍哈希表，O(n)O(n)，52 ms，16.1 MB
思路：将数组哈希之后，可以直接根据索引值找到数字。比如：`L = [1,3,5,7,8,9]` → `L = [0,1,0,3,0,5,0,7,8,9]`，就能保证`L[3]=3`，`L[7]=7`
那么只要遍历一遍，并在遍历到 3 的时候，查找有没有 L[12-3] 即 L[9] 既可
Python中的哈希可以用字典来实现。但是字典中的键不允许重复，那么只好将值当做键，将位置列表当做值了

```Python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        # 将列表转为字典，键为值，值为位置的列表
        dmap = {}
        for i,v in enumerate(nums):
            if v in dmap: dmap[v].append(i)
            else: dmap[v] = [i] # todo: 其实这里可以优化，直接记录值而非列表。因为正确答案中的重复数，必定最多两个。则记录值时会被后面的覆盖，下一次循环又是从前面开始的。
    
        # 遍历列表后，在字典中找到差值对应的键，并获取和自己不同的位置
        for i,v in enumerate(nums):
            diff = target-v
            if diff not in dmap: continue
                
            positions = dmap[diff]
            if positions[0] == i:
                if positions.__len__() == 1: continue # 可能是[3,2,4]=6时找到了3
                else: return [i, positions[1]] # 也可能是[3,3]=6时找到第一个3
            else: return [i, positions[0]]
```

### 4，一遍哈希表，O(n)O(n)，52 ms，15.1 MB
只遍历一次，一边放入字典，一边判断。
```Python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dmap = {}
        for i,v in enumerate(nums):
            diff = target-v
            if diff in dmap:
                return [dmap[diff], i]
            dmap[v] = i
```