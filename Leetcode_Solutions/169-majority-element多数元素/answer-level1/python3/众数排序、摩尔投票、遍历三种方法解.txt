一、众数排序：
    若已知众数必定存在，则众数的个数>其他数的个数，若对数组进行排序后，则数组最中间的数必定为众数。即众数个数>n/2；
    基本思路：排序+数组中间的数可得出结果。
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort();
        # return(nums[math.ceil(len(nums)/2)]);
        # 注意下标从0开始
        return nums[len(nums)//2];
```

二、摩尔投票算法：
    根据候选人思想，声明两个变量，candidate和count；
    如果当前数等于candidate则+1，否则-1；
    当count=0时，更换候选人。
    时间复杂度o(n)；
```
# class Solution:
#     def majorityElement(self, nums: List[int]) -> int:
#         candidate = 0;
#         count = 0;
#         for i in nums:
#             if(count == 0):
#                 candidate =i;
#             if(candidate == i):
#                 count+=1;
#             else:
#                 count-=1;
#         return candidate;
```


三、字典遍历：
    原理很简单，就是创建一个字典，根据字典的独有性质，即下标为键key，键的值为value；也就是说可以通过键来访问值。即dict[key] = value；
    将数组的元素存入字典的键，其值value进行统计出现的次数，然后输出值value>n/2的键就行了。
    键的初始value设为1;
![image.png](https://pic.leetcode-cn.com/eee87c7d0d851bdf405ae9cb7145730c3a681ae8f614defdfa12de2218cd8513-image.png)

```
# class Solution:
#     def majorityElement(self, nums: List[int]) -> int:
#         map = dict();
#         for i in nums:
#             if i not in map.keys():
#                 map[i] = 1;
#             else:
#                 map[i]+= 1;
#         for i in nums:
#             if(map[i] > len(nums)//2):
#                 return i;
```
