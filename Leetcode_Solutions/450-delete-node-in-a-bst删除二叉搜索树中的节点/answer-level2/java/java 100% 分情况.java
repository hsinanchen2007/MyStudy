晚了  不写想法了
```
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
    TreeNode result;
    TreeNode minParent;
    public TreeNode deleteNode(TreeNode root, int key) {
        result = root;
        traverse(root,key,null);
        return result;
    }

    private void traverse(TreeNode root, int key, TreeNode parent){
        if(root==null){
            return;
        }
        if(root.val>key){
            traverse(root.left,key,root);
        }else if(root.val<key){
            traverse(root.right,key,root);
        }else{
             if(root.left==null&&root.right==null){
                 if(parent!=null){
                if(parent.left==root){
                    parent.left=null;
                }else{
                    parent.right=null;
                }
                
                 }else{
                     result = null;
                 }
            }else if(root.right==null){
                if(parent!=null){
                    if(parent.left==root){
                        parent.left=root.left;
                    }
                    else{
                        parent.right = root.left;
                    }
                }else{
                    result = root.left;
                }
            }else{
                 TreeNode leftmin = findMin(root.right);
                  if(minParent!=null){
                        minParent.left=leftmin.right;
                    }
                 if(root.right!=leftmin){
                    leftmin.right = root.right;
                 }
                 leftmin.left = root.left;
                 
                if(parent!=null){
                if(parent.right==root){
                    parent.right=leftmin;
                   
                }else{
                    parent.left=leftmin;
                }
                
                }else{
                    result = leftmin;
                    result.left = root.left;
                }
            }

        }
        
    }
    private TreeNode findMin(TreeNode node){
        while(node.left!=null){
            minParent = node;
            node=node.left;
        }
        return node;
    }
}
```
