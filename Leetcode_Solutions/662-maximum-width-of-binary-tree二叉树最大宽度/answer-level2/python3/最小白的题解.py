```
'''
LeetCode 662. 二叉树最大宽度
Given a binary tree, write a function to get the maximum width of the given tree.
The width of a tree is the maximum width among all levels.
The binary tree has the same structure as a full binary tree, but some nodes are null.
The width of one level is defined as the length between the end-nodes (the leftmost
and right most non-null nodes in the level, where the null nodes between
the end-nodes are also counted into the length calculation.
Example 1:
Input:

           1
         /   \
        3     2
       / \     \
      5   3     9
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input:
          1
         /
        3
       / \
      5   3
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input:
          1
         / \
        3   2
       /
      5
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input:
          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
Note: Answer will in the range of 32-bit signed integer.

题目大意：
给定一个二叉树，编写一个函数来获取这个树的最大宽度。
树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。
每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
示例 1:
输入:

           1
         /   \
        3     2
       / \     \
      5   3     9
输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
示例 2:
输入:

          1
         /
        3
       / \
      5   3

输出: 2
解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
示例 3:
输入:
          1
         / \
        3   2
       /
      5

输出: 2
解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
示例 4:
输入:

          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
注意: 答案在32位有符号整数的表示范围内。

解题思路：
读题，注意 3 2与 3 null null 2，是不同宽度的
由于我们需要将给定树中的每个节点都访问一遍，我们需要遍历树。我们可以用深度优先搜索或者宽度优先搜索将树遍历。
这个问题中的主要想法是给每个节点一个 position 值，如果我们走向左子树，那么 position -> position * 2，
如果我们走向右子树，那么 position -> positon * 2 + 1。当我们在看同一层深度的位置值 L 和 R 的时候，宽度就是 R - L + 1。
这个其实就是下标从1开始的，位置索引关系，当然你用下标从0开始的公式，也一样，因为这道题是求的差值

方法 1：bfs
宽度优先搜索顺序遍历每个节点的过程中，我们记录节点的 position 信息，对于每一个深度，第一个遇到的节点是最左边的节点，最后一个到达的节点是最右边的节点。
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        queue = [(root, 0, 0)] # 队列实现bfs，忘了bfs可以百度搜一下，队列实现按层宽度搜索
        cur_depth = left = ans = 0
        for node, depth, pos in queue:
            if node:
                queue.append((node.left, depth+1, pos*2))
                queue.append((node.right, depth+1, pos*2 + 1))
                if cur_depth != depth: # 到了下一层
                    cur_depth = depth # 更新当前深度为当前层
                    left = pos # 下面分析了，需要更新下一层的左侧基准left
                ans = max(pos - left + 1, ans) # 不断更新为最大值，pos - left + 1就是该层最右边节点下标-最左边节点下标+1
                # 这里你要细想一下，ans何时计算当前层最大的，其实大部分时候都是在层内更新
                # 我们重点思考，题目求某层最大宽度
                # 那当if cur_depth != depth: # 到了下一层，此时，队列先进先出for循环遍历当其实是下一层第一个节点了
                # 此时pos为下一层的位置，如果还计算ans = max(pos - left + 1, ans)，那不就计算下一层第一个节点和上一层节点的宽度了嘛、
                # 所以我们要更新left为pos，重新更新当前层的左侧边界，因为pos是累计计算的
                # PS：新一层第一个节点的pos不是0，这个重点理解，理解这个才能理解这道题
        return ans

方法2：dfs
按照深度优先的顺序，我们记录每个节点的 position 。对于每一个深度，第一个到达的位置会被记录在 left[depth] 中。
然后对于每一个节点，它对应这一层的可能宽度是 pos - left[depth] + 1 。我们将每一层这些可能的宽度去一个最大值就是答案。
class Solution(object):
    def widthOfBinaryTree(self, root):
        self.ans = 0
        left = {}
        def dfs(node, depth = 0, pos = 0): # 递归实现dfs
            if node:
                left.setdefault(depth, pos) #相当于更新每一层的左侧边界，同上面left = pos # 下面分析了，需要更新下一层的左侧基准left
                self.ans = max(self.ans, pos - left[depth] + 1) # 同上面ans = max(pos - left + 1, ans)
                dfs(node.left, depth + 1, pos * 2)
                dfs(node.right, depth + 1, pos * 2 + 1)
        dfs(root)
        return self.ans
'''
class Solution(object):
    def widthOfBinaryTree(self, root):
        self.ans = 0
        left = {}
        def dfs(node, depth = 0, pos = 0): # 递归实现dfs
            if node:
                left.setdefault(depth, pos) #相当于更新每一层的左侧边界，同上面left = pos # 下面分析了，需要更新下一层的左侧基准left
                self.ans = max(self.ans, pos - left[depth] + 1) # 同上面ans = max(pos - left + 1, ans)
                dfs(node.left, depth + 1, pos * 2)
                dfs(node.right, depth + 1, pos * 2 + 1)
        dfs(root)
        return self.ans
```
