看了很多题解和评论，有的要么没有解释和注释，有的解答的很模糊，一个也看不懂。我自己想了两种方法，注释的也很清晰易懂，都一次性题解成功，发上来跟大家分享。
```
class Solution:
    def jump(self, nums):
        n = len(nums)
        if n < 2:
            return 0

        # 跳跃计数
        jump_num = 0
        # 下一跳的位置
        next_i = -1
        for i in range(n - 1):
            # 每个元素能够跳跃的最大数
            num = nums[i]
            # 元素所在位置和所走的步数之和，再加上所到达位置的数字
            # 得到的最大值
            max_dist = 0
            # 只有起始位置和计算出的最佳跳跃位置需要处理
            if i != 0 and i != next_i:
                continue
            # 计算起始位置和最佳跳跃位置需要到达的下一个位置
            for k in range(1, num + 1):
                # 如果此位置加跳跃步数没有到达最后位置，则进行计算判断下一个跳跃位置
                if i + k < n - 1:
                    # 通过计算元素所在位置和所走的步数之和，再加所到达位置的数字
                    # 计算出最大值和下一个位置
                    if i + k + nums[i + k] > max_dist:
                        max_dist = i + k + nums[i + k]
                        next_i = i + k
                # 如果此位置加跳跃步数到达或超过最后位置，则跳跃步数加1，返回结果
                else:
                    jump_num += 1
                    return jump_num
            # 完成一次跳跃，则跳跃步数加1
            jump_num += 1

        return jump_num
```

```
class Solution:
    def jump(self, nums):
        n = len(nums)
        if n < 2:
            return 0

        # 跳跃计数，初始值为1
        jump_num = 1
        # 元素能够跳跃到的最大位置
        max_dist = nums[0]
        # 由max_dist得出跳跃的边界
        border = nums[0]
        for i in range(n - 1):
            # 遍历两个边界之间的元素，求出最大元素位置和最大跳跃数之和
            # 产生新的边界
            max_dist = max(max_dist, i + nums[i])
            # 元素每次到达跳跃的边界，则重新更新边界，跳跃计数增加1
            if i == border:
                border = max_dist
                jump_num += 1

        return jump_num
```

