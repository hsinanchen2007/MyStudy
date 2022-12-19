较简单的一道题目，和之前的一道两数和非常像

来源：力扣（LeetCode）
链接：[https://leetcode-cn.com/problems/two-sum-bsts/](https://www.zhangjc.site/5080-two-sum-bsts/)

## 分析
首先给定的二叉搜索树是很好的提示，即两组数据是有序的。

其次还有一点是，所需的两个数字分别位于两个数中，即我们需要从两组数据中得到恰好和为所需值的两个数。

### 思路一
一个非常简单的方案是，将其中一棵树放入哈希表中，再依次遍历另一颗树，对于每个元素检测其补值（Target - curNum）是否存在哈希表中。

此时时间复杂度为$O(min\{|M|, |N|\})$。（|M|，|N|分别为两棵树的大小）。

但这个方案需要使用哈希表，显然复杂度的常数较大，并且对空间也有一定的要求。

### 思路二
使用中序遍历将两棵树的元素分别保存（升序），使用双指针分别指向两个列表的头、尾。

此时可以借鉴文章开头提到的题目思路，不断移动双指针即可。

时间复杂度与空间复杂度均为$O(|M| + |N|)$。（暂未考虑中序遍历时的递归空间需求）

## 实现

思路一比较简单，思路二的实现如下：

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def inorder(node:TreeNode, li:list):
    if node == None:
        return
    inorder(node.left, li)
    li.append(node.val)
    inorder(node.right, li)

class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        li_1, li_2 = [], []
        inorder(root1, li_1)
        inorder(root2, li_2)
        p1, p2, len1 = 0, len(li_2) -1, len(li_1)
        
        while p1 < len1 and p2 >=0:
            judge = li_1[p1] + li_2[p2] - target
            if judge == 0:
                return True
            elif judge > 0:
                p2 -= 1
            else:
                p1 += 1
        return False
```
![](https://pic.leetcode-cn.com/ef5922f6716ca9bc30d69f26641c9c568d30d298e7bf1812b7aa08adc4fd68f4.png)