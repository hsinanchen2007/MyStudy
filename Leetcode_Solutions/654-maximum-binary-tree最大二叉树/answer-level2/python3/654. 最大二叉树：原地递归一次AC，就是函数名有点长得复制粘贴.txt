题目不难，就看怎么写得快，写得清晰，写得简便，并且能够减少赋值和调用，在以上提到的方面我都做得不够好，程序忽快忽慢不得头脑。

```python []
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if nums:
            maxi = nums.index(max(nums))
            r = TreeNode(nums[maxi])
            r.left = self.constructMaximumBinaryTree(nums[: maxi])
            r.right = self.constructMaximumBinaryTree(nums[maxi + 1: ])
            return r
```
![image.png](https://pic.leetcode-cn.com/11673ff1a54208313c835b923730a1406676e88895396a45e6485eca190dbdac-image.png)
![image.png](https://pic.leetcode-cn.com/5a44bc8dd8cf9b3f036dbf1a513d1456f07fa459039912a35ec8065b0e4948e8-image.png)


最大值查询是这题最大的时间瓶颈，一个`max()`，一个`index()`直接就把时间复杂度提升到了$O({N}^{2})$的级别，遍历树都是小时间了，用线段树能够更快一些，但确实麻烦不少。