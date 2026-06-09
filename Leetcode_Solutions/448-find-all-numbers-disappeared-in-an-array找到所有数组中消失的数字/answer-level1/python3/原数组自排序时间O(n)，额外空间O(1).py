就是因为nums[i]<=nums.length，所以一直nums[i]和nums[nums[i]]交换就行，一次遍历就可以把数组按位排好序，实际交换次数最大应该是nums.length-1。
当然，要论速度还是取负伪哈希快一些，这个算法最快也就220ms这样
```
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        nums=[0]+nums
        n=len(nums)
        for i in range(1,n):
            while nums[i]!=i:
                nums[nums[i]],nums[i]=nums[i],nums[nums[i]]
                if nums[nums[i]]==nums[i]:
                    break
        return [i for i in range(1,n) if nums[i]!=i]
```
以官方用例为例
```
扫描位置（i），交换次数，原数组
0 0 [0, 4, 3, 2, 7, 8, 2, 3, 1]
1 1 [0, 7, 3, 2, 4, 8, 2, 3, 1]
1 2 [0, 3, 3, 2, 4, 8, 2, 7, 1]
1 3 [0, 2, 3, 3, 4, 8, 2, 7, 1]
1 4 [0, 3, 2, 3, 4, 8, 2, 7, 1]
5 5 [0, 3, 2, 3, 4, 1, 2, 7, 8]
5 6 [0, 1, 2, 3, 4, 3, 2, 7, 8]
```
在位置1的时候，4次交换把2-4都换对了，所以直接跳到5，然后再换两次就有序了。
因为每个数字一开始都不在正确的位置上，所以交换次数很高，6次是正确次数，实际上还会有第7次一个无用交换