### 解题思路
思路来源于[中序和前序遍历构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/cong-qian-xu-he-zhong-xu-bian-li-xu-lie-gou-zao-er/)。
后序遍历顺序是 Left -> Right -> Root。

因此在后序遍历的数组中，最后一个元素就是树的根。在inorder序列中，这个根所在元素的两边就是它的左右子树。我们取postorder的倒数第二个数，它就是根的右子树或左子树。如此递归下去，我们就能重构整棵树。
### 变量
- 需要一个指针指向当前的根元素，即此指针是在后序数组中从后往前移动的。
- 需要一个memo，用来保存中序数组对应元素的索引，以实现快速查询。
- 两个局部变量保存题目所给的两个数组。
### 代码

```java
class Solution {
    int post_idx=0;
    int[] inorder,postorder;
    HashMap<Integer,Integer> map=new HashMap<>();
    
    //in_left和in_right代表的是当前根元素在inorder中的左界和右界。
    public TreeNode helper(int in_left,int in_right){
        if(in_left>=in_right)return null;
        TreeNode root=new TreeNode(postorder[post_idx--]);
        //寻找当前根节点在中序数组中的位置，以确定其左右子树
        int index=map.get(root.val);
        root.right=helper(index+1,in_right);
        root.left=helper(in_left,index);
        return root;
    }
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        //指向树的根
        this.post_idx=postorder.length-1;
        this.inorder=inorder;
        this.postorder=postorder;
        for(int i=0;i<inorder.length;i++)
            map.put(inorder[i],i);
        return helper(0,postorder.length);
    }
}
```
### 复杂度分析
时间复杂度：O(N)
空间复杂度：O(N)。存储整个中序数组的开销。