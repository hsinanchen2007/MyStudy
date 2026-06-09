# 题目分析

题目中要求将二叉树展开为链表，不难看出，这里展开的顺序是**前序遍历**，即先访问根，再访问左子树，最后访问右子树。

一个很直观的想法就是，先把**左子树展开成为链表l**，再把**右子树展开成链表r**，最后**节点的右端先指向左子树对应的链表l，再指向右子树对应的链表r**即可，可以理解为**root.right->l->r**。

# 前序遍历简介

为了方便对前序遍历不了解的读者，这里对前序遍历进行一个简单说明。

维基百科中“树的遍历”词条前序遍历如下图：
![330px-Sorted_binary_tree_preorder.svg.png](https://pic.leetcode-cn.com/8b82ff7aa8843691e3b11f9349777e5af39408ea8cdd2bcd5c18e999ce5503e8-330px-Sorted_binary_tree_preorder.svg.png)

前序遍历的顺序为：**根节点->左子树->右子树**，具体到图中而言，针对第一层，我们先经过**根节点**F，然后经过F的**左节点**B，当左节点B遍历完成后，再回来遍历**右节点**G。对节点B而言，我们先经过**根节点**B，再到达**左节点**A，由于**左节点**A下面不存在其他节点，这时应该转向B的**右节点**D，然后依次遍历D的**左、右节点**C和E即可。

因此，遍历顺序为 F-> B-> A-> D-> C-> E-> G-> I-> H。

# 解题思路

如上文所述，直观的想法是**先将左右子树分别展开，再进行连接**，因此我们可以将程序设计为递归程序，flatten函数负责对输入节点进行展开。

针对递归程序，我们需要考虑几点：

**1. 终止条件**

对于二叉树而言，当root=None时，说明我们到达了一个空节点，该节点没有任何意义，直接返回即可。因此一般可以将root == None设为终止条件，返回None。

**2. 程序主体**

程序主体中应该先分别将左子树root.left和右子树root.right展开成链表，然后**先将子节点root的右端指向左子树的链表，再将左子树链表的最后一个非空节点的右端指向右子树的链表**。

值得注意的是，**要记得将root的左边清空**，否则会出现问题。

**3. 返回值**

程序中相当于将root节点及以下的所有节点**展开为以root为头的节点**，因此直接返回root即可。

# 具体代码

```
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root == None:
            return None 

        l = self.flatten(root.left)  # 左子树展开为链表
        r = self.flatten(root.right) # 右子树展开为链表


        root.right = l               # 将左子树连接到root的右边
        node = root                  # 寻找当前链表的最右端
        while node.right:            # node从root开始是考虑到l==None的情况
            node = node.right
        node.right = r               # 将右子树连接到当前链表的最右段
        
        root.left = None             # 清空root的左子树

        return root
```
