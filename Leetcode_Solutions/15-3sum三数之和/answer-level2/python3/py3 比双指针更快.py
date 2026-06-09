```
ans = []
        counts = {}
        for i in nums:
            counts[i] = counts.get(i, 0) + 1

        nums = sorted(counts)

        for i, num in enumerate(nums):
            if counts[num] > 1:
                if num == 0:
                    if counts[num] > 2:
                        ans.append([0, 0, 0])
                else:
                    if -num * 2 in counts:
                        ans.append([num, num, -2 * num])
            if num < 0:
                two_sum = -num
                left = bisect.bisect_left(nums, (two_sum - nums[-1]), i + 1)
                for i in nums[left: bisect.bisect_right(nums, (two_sum // 2), left)]:
                    j = two_sum - i
                    if j in counts and j != i:
                        ans.append([num, i, j])

        return ans
```
大佬的答案，只记述一下思路
1. 建立元素与出现次数的map表，同时达到去重目的，这一步的时间复杂度为O(n)；
2. 按key值排序，时间复杂度最大为O(nlogn)；
3. 循环排序后的nums；
4. 处理小于0元素，寻找与num加起来能得到0的最小整数(two_sum - nums[-1])的位置，从i+1的位置开始找，避免重复；
5. 查找最大整数所在位置bisect.bisect_right(nums, (two_sum // 2), left)
6. 特殊处理包含0和two_sum // 2出现次数两次以上的情况
总的最大时间复杂度应该为O(n^2)