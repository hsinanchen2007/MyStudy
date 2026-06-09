### 解题思路
1.递归+双指针：
先中序遍历，得到二叉搜索树的有序数列，此时问题转化为658题：找到 K 个最接近的元素
时间空间复杂度都是N
2.在中序遍历过程中去比较，总的来说是先去k个节点的值放入数组，然后时刻判断是否需要更新数组，直至当前探索的节点值与目标的距离小于等于数组中第一个元素与目标值的距离，这种情况则是探索完成
时间复杂度最坏情况下是N，也就是k个元素是中序遍历的最后k个元素
空间复杂度为H
3.是第二种方法的非递归形式，但时间复杂度会比第二种高，因为第二种只要找到了就直接return，这种会把全部节点遍历完才return
4.这种方法实在过于复杂，之后用C++写的时候再去看看
要求当树为AVL的时候，在O(max(k, logN))时间完成这道题。
思路是首先找到和target最接近的节点，然后用双指针依次把剩余的k-1个节点的值加到结果里。
a.找里target最近的节点cur就是 270. Closest Binary Search Tree Value 这道题。（在AVL树中，这个时间复杂度最快为logN）
b.之后以cur为起点，向前向后找第2接近的节点即可。AVL里找某个节点的中序遍历下的上一个or下一个节点的平均时间复杂度为O(1)。所以整个时间复杂度是O(k).
找当前节点cur在中序遍历下的的上一个节点。
(1) 若cur有左孩子, 则上一个节点即为cur->left的最右孩子
(2) 若cur无左孩子, 则看cur是不是其父亲的右孩子，若是则其父亲即为目标节点，否则继续找父亲的父亲，看父亲的父亲的右孩子是否是父亲，若是，则父亲的父亲为目标节点。依次类推，直到没父亲节点了，则说明已经找到了最小的节点。
找当前节点cur在中序遍历下的下一个节点。和之前对称，把前面描述的左孩子都换成右孩子，右孩子换成左孩子即可。
[https://leetcode-cn.com/problems/closest-binary-search-tree-value-ii/solution/follow-up-c-ologn-time-ologn-space-by-kyriemao/]()

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
#1.递归+双指针
    def closestKValues(self, root, target, k):
        """
        :type root: TreeNode
        :type target: float
        :type k: int
        :rtype: List[int]
        """
        def inorder(r):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        arr=inorder(root)   
        size = len(arr)
        left = 0
        right = size - 1
        remove_nums = size - k
        while remove_nums:
            if target - arr[left] <= arr[right] - target:
                right -= 1
            else:
                left += 1
            remove_nums -= 1

        return arr[left:left + k]
#中序遍历过程中去进行操作
    def closestKValues(self, root, target, k):
        """
        :type root: TreeNode
        :type target: float
        :type k: int
        :rtype: List[int]
        """
        if not root:
            retrun 
        res = []
        self.inorder(root, target, k, res)
        return res
        
    def inorder(self, root, target, k, res):
        if not root:
            return
        self.inorder(root.left, target, k, res)
        if k > len(res):
            res.append(root.val)
        elif abs(res[0] - target) > abs(root.val - target):
            res.pop(0)
            res.append(root.val)
        else:
            return
# 非递归方法
def closestKValues_3(self, root: TreeNode, target: float, k: int) -> List[int]:
        if not root:
            return
        DONE = 1 # 已读结点
        UNDO = 0 # 未读结点
        res = []
        stack = [(root, UNDO)]
        while stack:
            node, status = stack.pop()
            if not node:
                continue
            if status == UNDO:
                stack.append((node.right, UNDO))
                stack.append((node, DONE))
                stack.append((node.left, UNDO))
            elif status == DONE:
                if k > len(res):
                    res.append(node.val)
                elif abs(res[0] - target) > abs(node.val - target):
                    res.pop(0)
                    res.append(node.val)
        return res   
```