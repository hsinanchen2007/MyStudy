### 解题思路
![image.png](https://pic.leetcode-cn.com/a9e30873bc3a4bb43916891e50bd6981642819128eaa323eedb1aeb3c71b5996-image.png)

先做第一题，再回来做这个你会发现真TM简单。不要学我随机做题目。。。。然后回去做第一题去了
难受
总体来说，就是把新数加到第一题数组的最后，也就是插入根节点的右子树（除非他比根节点就大），
然后呢，我们判断下，若是他比最后一个节点小，那么自然的成为最后一个节点的右孩子。
若是他比最后一个节点大，那么好了，我们要找到他比右边到底哪个节点小，找到比他大的那个节点，由于他在数组中的顺序在这个节点右边，所以他要插入比他大的右孩子，并把原来的那一坨右孩子变为自己的左孩子即可。
一共就这三种情况。
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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
       if(root==null)
        	   return new TreeNode(val);
           else if(root==null||root.val<val){//若是自己比根节点都大，那么树变为自己的左孩子
            	TreeNode temp=new TreeNode(val);
            	temp.left=root;
            	return temp;
            }
          TreeNode  root1= root;
          TreeNode root2=root;
          while(root1!=null&&root1.val>val){
        	  if(root1.right!=null&&root1.right.val>val){
        	   root1=root1.right;//因为是最后一个数组的值，那么他必然是树的右边的节点
        	  }
        	   else{
        		   break;
        	   }
          }
          if(root1.right==null&&root1.val>val){
        	  root1.right=new TreeNode(val);//若是节点的右孩子空啦且自己比该节点小，那么好了，直接插入吧
          }
          else if(root1.right!=null&&root1.right.val<val){
        	  root2=root1.right;//否则就是自己比最后一个节点大，那么要修改指针，最后变为非叶节点，原来的一坨，变为自己的左孩子
        	  root1.right=new TreeNode(val);
        	  root1.right.left=root2;
          }
          
            return root;
    }
}
```