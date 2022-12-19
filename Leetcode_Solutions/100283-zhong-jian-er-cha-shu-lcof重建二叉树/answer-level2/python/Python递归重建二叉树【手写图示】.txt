#### 分析前序中序特点
前序是：根，左子树， 右子树
中序是：左子树，根，右子树
而且这里要特别注意，这样表示是宏观的，遍历实则是对每一个节点的遍历，
所以从微观讲，对于每个节点而言，前序都是要先遍历根节点。
中序是你到任何一个节点了如果它有左节点，那你必须先遍历它的左节点，但是到了左节点
之后如果它还有左节点，你依然要找下去。。。。。以此类推

#### 回归题目
根据这两个遍历数组我们直接可以得出的信息是：
1. 前序遍历的数组第一位，一定是现在这两个遍历的根节点
2. 根据1找出的根节点，我们可以找出根节点在中序遍历的索引位置，用这个索引我们可以找出中序中被分割的左右子树的序列，注意在这个数组拿到的序列肯定是中序的顺序。
3. 最容易忽略的一个信息是：这个索引值代表了左子树的长度！！！！！！让我分割前序遍历的左右子树成为可能。
![IMG_FC361F3003DA-1.jpeg](https://pic.leetcode-cn.com/d8d929fdb30d14f6f4b1e67c1a79322acc8b6b79ab2955eba2fcadd03f9ce92f-IMG_FC361F3003DA-1.jpeg)
#### 创造递归条件
既然从根节点的树符合这个规律，而遍历是对于每一个节点都一样的，那么它的左子树，右子树都会符合这个规律啊，所以这就给递归创造了条件。
这时候我们就要构造左右子树分别的前序中序遍历的数组，把大的问题可以切分成左右子树的重建了，
我们只需要把找到的根节点的left和right指向左子树的重建和右子树的重建即可。
如何分割呢：
![IMG_74D37B77838C-1.jpeg](https://pic.leetcode-cn.com/08569498f5edb28fdbf69b03cdf3b54250b1f7da66ada8c7c1e786523d6b3632-IMG_74D37B77838C-1.jpeg)


#### 寻找递归终止条件
那就是如果我分割到没有左子树或者右子树的时候，那么就意味着根节点的left或者right要指向None呗


#### 上代码
```
class Solution(object):
    # 递归
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        curr_root_val = preorder[0]
        curr_root_index_in_inorder = inorder.index(curr_root_val)
        rootNode = TreeNode(curr_root_val)
        left_tree_pre = preorder[1:1+curr_root_index_in_inorder]
        left_tree_in = inorder[:curr_root_index_in_inorder]
        right_tree_pre = preorder[1+curr_root_index_in_inorder:]
        right_tree_in = inorder[1+curr_root_index_in_inorder:]
        rootNode.left = self.buildTree(left_tree_pre, left_tree_in)
        rootNode.right = self.buildTree(right_tree_pre, right_tree_in)
        return rootNode
```
