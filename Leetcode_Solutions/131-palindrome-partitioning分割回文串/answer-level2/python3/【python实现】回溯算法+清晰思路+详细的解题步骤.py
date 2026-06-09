解题思路：
`s`字符串是从左到右分割的，因此每次分割都只需要将后边剩余的字符串中分割为左右两部分，也只需要判断左部分是否满足回文

解题方法：回溯算法
1. 判断切割结果是否满足目标条件：`index` == `len(s)`
2. 遍历所有可行的分割情况：用`index`表示当前剩余的未分割的字符串的头，`i`在`[index ~ len(s)]`中遍历
3. 剪枝：判断切割的左边，即`s[index:i+1]`是否满足回文。如果不满足，则跳过；否则，执行4
4. 记录结果：将分割的结果记录到临时列表`tmp`中
5. 递归：因为在`i`位置切割，因此从`i+1`开始就是剩余的未分割的字符串，故要传入`i+1`作为下一层的`index`

![1.jpg](https://pic.leetcode-cn.com/e87de2e78198da368d846458ba912dfe83e71d97e2c10ab9c4706c3dda36076a-1.jpg)


```
class Solution:
    def partition(self, s):
        # 边界条件判断
        if not s:
            return []

        # 返回列表
        res = []
        self.backtracking(s, 0, [], res)
        return res

    def backtracking(self, s, index, tmp, res):
        # 判断是否满足条件
        if index == len(s):
            res.append(tmp.copy()) # 保存结果
            return

        # 遍历所有可能情况
        # i为切割的位置，index为切割的起始位置
        for i in range(index, len(s)):
            # 剪枝：判断切割的左边是否满足回文
            # 如果不满足，则跳过
            if not self.check(s[index:i+1]):
                continue

            tmp.append(s[index:i+1]) # 记录分割结果

            # 递归：从当前切割的后一个位置递归
            self.backtracking(s, i+1, tmp, res)

            # 回溯：
            tmp.pop()

    def check(self, s):
        for i in range(int(len(s)/2)):
            if s[i] != s[-(i+1)]:
                return False
        return True
```