### 解题思路
题目中给出二叉树的前序和中序遍历，要求重构这棵二叉树
- 前序遍历 preorder = [3,9,20,15,7]
- 中序遍历 inorder = [9,3,15,20,7]

由于我们无法从前序或中序遍历中直观的得出答案，因此要解决此问题，首先需要研究前序和中序遍历的特点。
- 首先是前序遍历，前序遍历的特点是，第一个元素即为根结点的值，因此我们可以直接得到根结点的值。
- 其次是中序遍历，中序遍历根节点的值位于序列中间，同时，其左子树的结点全部位于根节点值的左侧，其右子树的结点全部位于根节点右侧，通过前序遍历得到根结点值，我们可以在中序遍历中找到根节点的位置。

在中序遍历序列中找到根节点的位置后，这个问题就很好解决了，大致思路如下：
1. 由于前序遍历首元素为根节点值，首先可以得到根节点值。
2. 在中序遍历序列中通过根节点的值，寻找根节点的位置。
3. 将左右两边的序列分割开来，并重构为根节点的左右子树。（递归分治）
4. 在新的序列中，重复上述步骤，通过前序遍历再次找到当前子树的根节点，再次进行分割。
5. 直到分割到仅剩下一个结点时，开始回溯，从而完成整棵二叉树的重建。

### 图解
![1.png](https://pic.leetcode-cn.com/b73f65d274fd0c8ca2886604b084c500b1ddd968859359be9793c9a71d01a516-1.png)
***
![2.png](https://pic.leetcode-cn.com/f57e59968dbd44708e69fbb343ee9c3ad729cff8aa3ac0d63dddd171ac9d1bad-2.png)
***
![3.png](https://pic.leetcode-cn.com/6289e4396fe32417cc2db928d01c68afce7416aa2bd332eda7d716dbad83ca7a-3.png)

我们用Java代码实现此思路：
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTreeCore(preorder, inorder, 0, preorder.length-1, 0); 
    }

    public TreeNode buildTreeCore(int[] preorder, int[] inorder, int start, int end, int index){
        if(end < start) return null;  //如果划分结果没有元素，返回null
        if(end == start) return new TreeNode(preorder[index]);   //划分结果只剩一个元素，返回此元素对应的结点
        TreeNode node = new TreeNode(preorder[index]);    //构建当前根节点
        int pos = 0;
        while (inorder[pos] != preorder[index]) pos++;    //找到根节点位置
        node.left = buildTreeCore(preorder, inorder, start, pos - 1, index+1);  //划分左子树
        node.right = buildTreeCore(preorder, inorder, pos+1, end, index+pos-start+1);   //划分右子树
        return node;   //返回当前结点
    }
}
```