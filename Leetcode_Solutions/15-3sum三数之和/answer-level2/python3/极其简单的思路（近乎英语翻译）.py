由于样例中给出的三元组都是有序的，所以显然应该先对输入序列排序。本题至少应该优化到N^2，所以排序的复杂度可以不计。
设置三个指针变量，i、j、k，代表三个数在数组中位置，如果i从开始向末端移动，那么j从i+1的位置向末端移动，由于nums是有序的，对同一个i而言，k只需要从nums的末端扫描到j+1的位置即可。
优化的关键在于，如果nums[i]和num[i-1]一样的话，直接continue就好了，因为如果nums[i]==nums[i-1]，由num[i]计算出的结果必然是num[i-1]的子集。
```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = set()
        n = len(nums)
        for i in range(n):
            if i>0 and nums[i]==nums[i-1]:
                continue
            index = n-1
            for j in range(i+1,n):
                a, b = nums[i], nums[j]
                c = 0 - a - b
                if c<b:
                    break
                while nums[index]>c and index>j+1:
                    index = index - 1
                if nums[index]==c and index>j:
                    ans.add((a,b,c))
        return list(ans)
```