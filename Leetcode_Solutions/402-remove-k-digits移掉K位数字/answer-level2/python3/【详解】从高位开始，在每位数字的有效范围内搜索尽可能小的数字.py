# 如果要剩下的数字最小，那么数字从左开始的每一位都要尽可能地小，因此我们要从剩余数字的高位开始，在**有效范围**内找到最小的数字。

# ## 何为有效范围？

# 比如这个栗子：

# ```
输入: num = "1432219", k = 3
# ```

# 要求删除 3 位数字，留下 4 位数字。那么第 1 位数字的查找有效范围是 `1432`，即下标 `0 ~ 3`。因为如果我们再往后选择，比如选择第 5 位数字 2，那么我们就无法完整地凑齐 4 位数字了。

# 可以观察到规律：

# - 第 1 位数字有效范围：下标 `0 ~ 3`
# - 第 2 位数字有效范围：下标 `1 ~ 4`
# - 第 3 位数字有效范围：下标 `2 ~ 5`
# - ……

# 假设我们要从长度为 `length` 的字符串 `num` 中删除 `k` 位数字，那么第 `x` 个数字的有效查找范围是下标 `x-1 ~ k+x-1`。

# ## 整体思路

# 整理一下思路：

# 1. 从高位开始逐一查找每一位数字尽可能小的取值。其中，第 `x` 位数字的有效取值范围是 `x-1 ~ k+x-1`
# 2. 找到最小值后记录最小值 `min_num` 以及对应的下标 `min_index`
# 3. 设置下一轮的查找开始位置为 `min_index + 1` 
# 4. 循环此过程，直到完成所有数字的查找

# ## 实现

# ```python
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        num_length = len(num)
        if num_length <= k:
            return "0"
        
        left_count = num_length - k
        res = ""
        count = 0
        begin = 0
        
        while count < left_count:
            min_index = 0
            min_num = float('inf')
            for i in range(begin, k + count + 1):
                # 找到最小数
                if int(num[i]) < min_num:
                    min_index = i
                    min_num = int(num[i])
            # 把找到的最小数加入结果列表
            res += str(min_num)
            # 设置下一轮查找范围的起点
            begin = min_index + 1
            count += 1
            
        return "0" if len(res) == 0 else str(int(res))
# ```

# ----

# ## 🐱

# - 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
# - 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
# - 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

# ![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)