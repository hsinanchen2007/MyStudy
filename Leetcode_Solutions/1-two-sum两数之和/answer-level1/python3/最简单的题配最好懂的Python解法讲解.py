### 对于小白来说思路最重要
#### 题目解读：
1. 给定一个目标值
2. 在给定数组里找到哪两个数字的和等于目标值

#### 目标代码：nums[i]+nums[j] = target
* 是不是有两个指针i，j
* 是不是可以用双指针法

解法1.双指针
1. 把nums数组排序
2. i从头开始，j从尾部开始
    * 判断 nums[i]+nums[j] == target

代码
```
def solution(nums,target):
    nums = sorted(nums)
    i,j = 0,len(nums)-1
    while i < j: # 没有这个限制，整个程序就会无限操作下去
        if nums[i]+nums[j] == target:
            return [i,j]
        elif nums[i]+nums[j] > target:
            j = j-1 # 因为从小到大已经排好序了，所以和太大的话就找小一位的
        elif nums[i]+nums[j] < target:
            i = i+1
```
这个解法比较好理解，但是时间复杂度和空间复杂度都没有满足题目每个元素只用一次的要求；不过作为我们小白，能想出这个方法并写出能跑通的代码已经是一件值得鼓励的事啦～

解法2. 字典
1. 为了满足每个元素只用一次的要求，我们查找过的元素存起来不就好啦
    * 这里就用到“字典”这个数据结构，不懂的小伙伴看这里：https://www.w3schools.com/python/python_dictionaries.asp
    * 打不开的学会科学上网
2. 遍历nums
    * 这次我们看target-nums[i]的值，我们之前有没有找到过[从字典里找到j]
        * 如果有则返回[i,j]
        * 否则我们把nums[i]存进字典里去

代码

```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        record = {} # 简历字典
        for i in range(len(nums)): # 遍历数组
            temp = target - nums[i] 
            if temp in record: # 如果满足条件，则说明
                return [record.get(temp),i]
            else:
                record[nums[i]] = i

```

作为0基础小白，刷题大半年，曲曲折折断断续续，走了无数弯路，但是我现在能骄傲的说：咱也是能刷medium的人儿啦
第一次写回答，是给自己的一个鼓励，也希望能鼓励到更多更多想我一样的同学。刷题真的不容易，没有几个是从小玩信息竞赛长大的，我包括我身边学cs的同学，他们也做不到一上来就秒medium的题，甚至很多easy题目也不会，希望大家在刷题的道路上能坚持再坚持✊，真的不用担心付出的辛苦，谢谢大家，也谢谢自己，共勉