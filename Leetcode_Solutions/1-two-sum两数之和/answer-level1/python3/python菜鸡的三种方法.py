### 解题思路
感觉基本的几种思路大同小异，但是具体实现的细节不同，菜鸡我技术很差，读代码一般，只能说大概了解别人的思路，然后尽量用自己理解的语法实现
### 方法一：
```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        while i < len(nums):
            n = target - nums[i]
            m=set(nums[i+1:])
            if n in m:
                return [i,nums.index(n,i+1)]
            else:
                pass
            i += 1
```
用时1204ms，每次用差值检查nums里面有没有目标值，有的话用index搜出来
set会自动去重，index只返回第一个值的索引，所以这里用i+1限制一下范围
### 方法二：
```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        m = []
        while i < len(nums):
            n = target - nums[i]
            if nums[i] in m:
                return [m.index(nums[i]),i]
            else:
                m.append(n)
            i += 1
```
用时352ms，我觉得我只有七秒钟记忆，我已经想不起来我这一步的思路是啥了，根据我的笔记：当case是[3,3],6这种情况的时候，如果用之前的思路，以差值在剩下的nums[i+1:]里查询，无法排除nums[i]本身，因此不如用nums[i]对差值组成的list进行查询
### 方法三：
```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        m = {}
        while i < len(nums):
            n = target - nums[i]
            if nums[i] in m:
                return [m[nums[i]],i]
            else:
                m[n]=i
            i += 1
```
用时48ms，看了一下大神解法，index那一步需要升级一下，字典的查询会比list快很多，但字典是无序且key必须唯一的结构，但nums可能会有重复值，我觉得可以直接用差值作为key，index作为value
### 方法四：
大概思路就是用散列法取代if nums[i] in m这一步，但是我太菜了，无法突破负数的限制，以后再说吧。。。