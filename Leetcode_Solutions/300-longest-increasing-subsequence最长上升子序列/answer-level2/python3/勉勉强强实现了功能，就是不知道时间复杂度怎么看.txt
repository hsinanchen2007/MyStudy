解题的思路：
对于[10,9,2,5,3,7,101,18]，从第一个元素遍历到最后一个元素，比如第一个为10，从第二个元素开始和10比较，如果比10大就计数+1，并且把10与这个比较数互换，把所有的数比较完就能得出从10开始的上升子序列的长度，以此类推就能得出最大的上升子序列
```
def lengthOfLIS(nums):
        res = []
        for i,num in enumerate(nums):
            count = 1
            for n in nums[i+1:]:
                if num < n:
                    num = n
                    count += 1
            res.append(count)
        return max(res)
```
