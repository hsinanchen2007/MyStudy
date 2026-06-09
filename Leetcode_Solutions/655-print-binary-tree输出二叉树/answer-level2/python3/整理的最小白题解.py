```
'''
LeetCode 655. 输出二叉树
Print a binary tree in an m*n 2D string array following these rules:
The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   /
  3
 /
4
Output:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].

题目大意：
在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：
行数 m 应当等于给定二叉树的高度。
列数 n 应当总是奇数。
根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。
你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空
，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。
每个未使用的空间应包含一个空的字符串""。
使用相同的规则输出子树。
示例 1:
输入:
     1
    /
   2
输出:
[["", "1", ""],
 ["2", "", ""]]
示例 2:
输入:
     1
    / \
   2   3
    \
     4
输出:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
示例 3:
输入:
      1
     / \
    2   5
   /
  3
 /
4
输出:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
注意: 二叉树的高度在范围 [1, 10] 中。

补充知识点：
满二叉树，就是一个二叉树全部节点都在，如
1
2 3
叶子节点23，全部是满的，除了叶子节点，每个节点都有左孩子以及右孩子
所以满二叉树，最大宽度，是2**（depth-1），你可以看这个例子，深度depth=2，最大宽度就是2**1=2

解题思路：
先得到高度，再得到宽度（满二叉树），再二分法遍历，每次填充中间的节点
对于这道题，和补充知识点有所不同，因为题目要求列数 n 应当总是奇数，就是说root要在中间，分为左子树右子树
那width计算就是2 ** depth - 1，看例子找规律就行，两层的输出宽度为2**2-1=3
class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        depth = self.getDepth(root)  # one - based
        width = 2 ** depth - 1  # 满二叉树
        out = [["" for j in range(width)] for i in range(depth)] # 初始化
        self.fill(root, out, 0, 0, width) # 填充节点值即可
        return out

    def fill(self, root: TreeNode, out: List[List[str]], depth: int, start: int, end: int): # 二分填充
        if not root or start > end:
            return
        middle = start + (end - start) // 2  # 中间位置
        out[depth][middle] = str(root.val)  # 填充，因为看例子，每次左子树右子树，中间值是当前子树的值
        self.fill(root.left, out, depth + 1, start, middle - 1) # 递归填充下一层左子树，开始为start，结束到mid-1
        self.fill(root.right, out, depth + 1, middle + 1, end)

    def getDepth(self, root: TreeNode) -> int:  # one-based
        if not root:
            return 0
        return max([self.getDepth(root.left), self.getDepth(root.right)]) + 1 # 求深度就是递归左右，递归一次深度+1
'''
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def printTree(self, root):
        depth = self.getDepth(root)  # one - based
        width = 2 ** depth - 1  # 满二叉树
        out = [["" for j in range(width)] for i in range(depth)] # 初始化
        self.fill(root, out, 0, 0, width) # 填充节点值即可
        return out

    def fill(self, root, out, depth, start, end): # 二分填充
        if not root or start > end:
            return
        middle = start + (end - start) // 2  # 中间位置
        out[depth][middle] = str(root.val)  # 填充，因为看例子，每次左子树右子树，中间值是当前子树的值
        self.fill(root.left, out, depth + 1, start, middle - 1) # 递归填充下一层左子树，开始为start，结束到mid-1
        self.fill(root.right, out, depth + 1, middle + 1, end)

    def getDepth(self, root):  # one-based
        if not root:
            return 0
        return max([self.getDepth(root.left), self.getDepth(root.right)]) + 1 # 求深度就是递归左右，递归一次深度+1
```
