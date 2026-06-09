# 从少到多依次列出所有的解。
我是随机答题所以先答的第60题[__力扣__](https://leetcode-cn.com/problems/permutation-sequence/)。
在第60题中的暴力枚举会超时，但用在此题恰到好处。

当数组只有一个元素时，只有一个解：[nums[0]]。

当有两个元素时，在第一个解的任意位置插入第二个元素，所以此时有两个解：[nums[0],nums[1]],[nums[1],nums[0]]。

当有三个元素时，依次在上两个解的任意位置插入地三个元素，所以此时有6个解：（太长不列出了，相信同学们可以看懂）。

... ...

以此类推，最后即可列出数组的全部排列。

此解法本质上依然是递归，但优化了入栈出栈的过程。
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result_tree = [[[nums[0]]]]
        i = 2
        while i<=len(nums):
            result_tree.append([])
            for item in result_tree[i-2]:
                for index in range(len(item)+1):
                    result_tree[i-1].append(item[:index]+[nums[i-1]]+item[index:])
            i+=1
        return result_tree[-1]

```

