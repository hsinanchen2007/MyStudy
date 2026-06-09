解法一：暴力模拟
双重循环交换，对两个数字进行交换随后比较取最大值
时间复杂度O(n³)

解法二：贪心规律
从头遍历，对于每个数字，判断其后的数字是否有比其更大的数字，若有则可以交换取得更大的数字。
**有点小问题**，有可能出现1993，正确答案为9913，而此规律下为9193

改正：若发现对应数字后有更大的数字x，在相同的x下，索引应该取更后面的。

时间复杂度O(n²) 优于暴力，空间复杂度O(1)

帮助理解的图例如下：
![image.png](https://pic.leetcode-cn.com/850a8d8d31f3bf4b56a2ecb59d1ab759245ab8a444216ea9b51238b645ae8b34-image.png)
从第二个图可以看到需要交换的位置处于第一条单调递减线之中，由此可以引入单调栈进行求解。


解法三：单调栈
维护一个单调非递增栈，当遇到比栈顶更大的数字时继续往后寻找更大的数字maxmun。随后不断出栈，直至栈为空或栈顶大于当前数字，此时原本的栈顶即为交换的位置
时间复杂度O(n)，空间复杂度O(n)

单调栈优化：
去掉栈，直接以一个指针来模拟栈顶
时间复杂度O(n)，空间复杂度O(1)

注：以上空间复杂度都建立在忽略将数字转为字符串的空间开销之上。

```
"""单调栈未优化版"""
class Solution:
    def maximumSwap(self, num: int) -> int:
        nums = list(str(num))
        stack = [nums[0]]
        i = 0
        for i in range(1, len(nums)):
            if nums[i] <= stack[-1]:
                stack.append(nums[i])
            else:
                break
        
        # 寻找用于交换的最大值
        maxmun = nums[i]
        for j in range(i, len(nums)):
            if nums[j] >= maxmun:
                maxmun = nums[j]
                i = j

        # 找到可交换位置
        while len(stack) > 0 and stack[-1] < maxmun:
            stack.pop()

        # 栈满的时候代表数字已经为最大，无需调整
        if len(stack) < len(nums):  
            nums[len(stack)], nums[i] = nums[i], nums[len(stack)]

        print(nums)
        return int(''.join(nums))
```