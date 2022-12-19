### 解题思路
哈哈哈哈，没有像官方题解里一样使用left和right两个索引（不知道是否会减少内存消耗？）
![image.png](https://pic.leetcode-cn.com/8dfac472fa1f0e823c71e2474bdb0cb35e7ee0d749d471ff756389a70821b95b-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.temp(nums)

    def temp(self, nodes):
        r = len(nodes) // 2 # 奇：中间元素，5//2=2(0,1,2,3,4); 偶：中间偏右，4//2 = 2(0,1,2,3)
        try: # 当某子树只含一个节点，如[1]时，r = len(nodes) // 2 = 1//2 = 0
            root = TreeNode(nodes[r])
            root.left = self.temp(nodes[:r])
            root.right = self.temp(nodes[r+1:])
            return root
        except: # 当某子树为[]时，也是r=0，但是nodes[r]不存在会报错
            return None

```