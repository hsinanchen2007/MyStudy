### 解题思路
题解里好像没有人用python3，我就自己写了一个给大家看看。
建议好好看看题解中onwaier大佬的那篇从论文角度讲解摩尔投票法，里面讲的很详细。
代码的重点在于用if和elif使first和second两个数不会相等。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        if not nums:return []
        first=second=nums[0]
        first_count=second_count=0
        for i in nums:
            if i==first:
                first_count+=1
            elif i==second:
                second_count+=1
            elif first_count==0:
                first=i
                first_count+=1
            elif second_count==0:
                second=i
                second_count+=1
            else:
                first_count-=1
                second_count-=1
        first_count=second_count=0
        for j in nums:
            if j==first:first_count+=1
            elif j==second:second_count+=1
        anw=[]
        if first_count>len(nums)/3:anw.append(first)
        if second_count>len(nums)/3:anw.append(second)
        return anw

```