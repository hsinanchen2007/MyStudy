解题思路一：
1.首先分析题意，一共有N+1的长度，N个数，那么必然是有一个数是重复了两次的；
2.先给列表排序，这样如果相邻的两个数相等，那么这两个数就是重复的；
3.技巧：i从1开始，和i-1比较，i++；效果就是 list[1] == list[0]--list[2] == list[1]-- ... --list[lengh] == list[lengh-1]
4.python语法注意：
    4.1：list.sort()方法使用前后，list的排序变化了；
    4.2 range(len(list))用这种方式取list的长度，然后在这个长度范围内每次循环+1，range（3）即 0 1 2；

```
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # print(nums)
        nums.sort()
        # print(nums)
        i=1
        length = len(nums)
        for i in range(length) :
            if i == 0：
                continue
            if nums[i] == nums[i-1]:
                return nums[i]
```

解题思路二：
使用while，和for相比不会出现i==0 的场景还需要单独处理；
```
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
         nums.sort()

         i=1
         length = len(nums)
         print(length)
         while i < length:
             if nums[i] == nums[i-1]:
                 return nums[i]
             i+=1
```


解题思路三：
使用一个数据结构：字典，把列表中的值存到字典中作为键值对的键，列表中的值的个数存成字典中键值对的值；
再循环判断，如果字典中 键值对的值大于1的话，那么这个键值对的键就是要找的值；
```
    class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        res_dict = {}
        for num in nums:
            if num in res_dict:
                res_dict[num] += 1
            else:
                res_dict[num] = 1
        for k in res_dict:
            if res_dict[k] > 1:
                # return res_dict[k]
                return k
```

            
            