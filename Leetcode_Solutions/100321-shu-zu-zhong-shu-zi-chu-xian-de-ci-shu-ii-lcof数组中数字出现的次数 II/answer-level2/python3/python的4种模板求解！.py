# 字典
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dict={}
        for i in (nums):
            try:
                dict[i]+=1
            except:
                dict[i]=1
        for j in dict:
            if dict[j]==1:
                return j
```
# 库函数Counter
Counter(x)：统计x中各元素出现次数

Counter(x).most_common(n)：出现次数最多的前n个元素及其次数

```
#举例
list= [1,2,3,4,5,1,1,1,2,2,3]
count = Counter(list)
res = count.most_common(3)
print(res) #[(1, 4), (2, 3), (3, 2)]
```
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        counter = collections.Counter(nums)
        #[-1]为最后一组，最后一组即为出现次数最少的组，[0]为最后一组中的第一个数字
        return counter.most_common()[-1][0]
        
    
```
# 求和
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        s1 = sum(nums)
        s2 = sum(list(set(nums)))*3
        return int(abs(s1-s2)/2)


```
# 排序
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        if nums[0] != nums[1]: 
            return nums[0]
        for i in range(1,len(nums)-1):
            if(nums[i] != nums[i+1] and nums[i] != nums[i-1]):
                return nums[i]
        return nums[-1]
```

