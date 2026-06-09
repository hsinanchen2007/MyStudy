根据前序遍历和中序遍历两个数组构造二叉树，观察可知，中序遍历的第一个结点为前序遍历中最左边的结点，故可以根据前序遍历一直构造左子树直到preorder[i]==inorder[j] 即如上例中首先构造出3-9，随后令j++， 这时inorder[j]有两种情况：
(1) inorder[j]是inorder[j-1]的父结点
(2) inorder[j]是inoder[j-1]的右子树中的结点
如果是情况(1)，由于一开始已经构造了从根节点到inorder[j-1]的结点，即可以从已经构造的结点中找出inorder[j]；如果是情况(2)，则从已构建的树中迭代地添加结点，这个结点的值为preorder中的值，直至有preorder[i]==inorder[j]。
根据上述分析，可以维护一个哈希表，记录已经构建的结点。
```
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, TreeNode> map = new HashMap<>();
        int i=0,j=0;
        TreeNode dummy=new TreeNode(0), cur=dummy;
        while(i<preorder.length) {
        	
        	//迭代地从preorder构造左子树
        	while(i==0 || i-1<preorder.length && preorder[i-1]!=inorder[j]) {
        		cur.left=new TreeNode(preorder[i]);
        		cur=cur.left;
        		map.put(preorder[i], cur);
        		i++;
        	}
        	if(i>=preorder.length) break;
        	//找到满足情况(2)的结点
        	while(j<inorder.length && map.containsKey(inorder[j]))
        		j++;
        	
        	cur=map.get(inorder[j-1]);
        	cur.right=new TreeNode(preorder[i++]);
        	cur=cur.right;
            map.put(cur.val, cur);
        }
        return dummy.left;
    }
}
```
