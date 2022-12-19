### 解题思路
后序遍历的特征是 **左子树-右子树-根节点**，中序遍历的特征是 **左子树-根节点-右子树**。  
  
所以 postorder 数组的从后往前就是 根节点，右子树，左子树，然后通过从 postorder 数组中获得的根节点，在 inorder 数组找到它对应的左右子树。例题中， postorder 数组的最后一位 3 就是根节点，而对应在 inorder 数组中，3 的左侧为{9}，右侧为{15,20,7}。所以{9}为左子树，{15,20,7}为右子树，同理继续从 postorder 中继续从后往前，那道 20 ，以此类推。
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
    private HashMap<Integer,Integer> mInorder = new HashMap<>();//用于记录中序数组中节点的的值，对应的数组下标
    private int pos;//记录从后序数组提取根节点的位置
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for(int i = 0; i < inorder.length; i ++){
            mInorder.put(inorder[i],i);
        }
        pos = postorder.length - 1;
        return build(postorder,0,postorder.length - 1);
        
    }
    public TreeNode build(int[] postorder,int s,int e){
        //如果超出界限则为空
        if(s > e) return null;

       //获取后序数组中的根节点，在中序数组中的位置
        int mindex = mInorder.get(postorder[pos]);
        TreeNode root = new TreeNode(postorder[pos]);
        pos--;
        //这里要注意的是，后序遍历的顺序是 左-右-根，所以倒过来生成数也就是 根-右-左
        root.right = build(postorder,mindex + 1,e);
        root.left = build(postorder,s,mindex - 1);
        
        return root;
    }
}
```