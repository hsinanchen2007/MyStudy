### 解题思路
此处撰写解题思路
数组索引用作hash也可以做，但是修改了原数组，所以不合适，只当是联练习了。
[41](https://leetcode-cn.com/problems/first-missing-positive/)
[442](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)
[268](https://leetcode-cn.com/problems/missing-number/)

同样的都是利用数组索引作为键，来构建hash,均摊复杂度分析。

这里有个数组的循环问题，快慢查找交叉点，然后双指针找到循环的入口，也就是重复数字。官方的题解。
### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # 乌龟兔子循环走
        p2=p1 = nums[0]

        while 1:
            p2 = nums[p2]
            p1 = nums[nums[p1]]
            if p2==p1:
                break
        
        ptr1 = nums[0]
        ptr2 = p2
        while ptr1 != ptr2:
            ptr1 = nums[ptr1]
            ptr2 = nums[ptr2]
        
        return ptr1


        # change input array
        # n = len(nums)

        # for i in range(n):
        #     while 1<=nums[i]<=n and nums[i]!=nums[nums[i]-1]:
        #         nums[nums[i]-1],nums[i]=nums[i],nums[nums[i]-1]
        
        # for i in range(n):
        #     if i+1!=nums[i]:
        #         return nums[i]



```