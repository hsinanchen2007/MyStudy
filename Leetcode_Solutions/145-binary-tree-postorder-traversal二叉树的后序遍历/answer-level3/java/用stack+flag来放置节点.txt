### 解题思路

前序遍历、中序遍历，都可以直接推到最左节点即可。
后序遍历，因为节点无法判断其右节点有无子孙，所以需要递归或者放入stack以便后用。
这是比较大的不同，造成一个节点被访问两次：一次是因为他有子孙节点，还有一次是被真正访问。

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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> retList = new LinkedList<Integer>();

        //skip special cases
        if(root ==null){
            return retList;
        }

        Stack<TreeNodeWrap> stack = new Stack<TreeNodeWrap>();
        TreeNodeWrap curNodeWrap = new TreeNodeWrap(root);
        stack.push(curNodeWrap);
        while(!stack.isEmpty()){
            curNodeWrap = stack.pop();
            TreeNode curNode = curNodeWrap.node;
            if(curNode.left==null && curNode.right==null){
                retList.add(curNode.val);//visit
            }else{
                if(!curNodeWrap.queued){

                    curNodeWrap.queued = true;
                    stack.push(curNodeWrap);

                    if(curNode.right!=null){
                        stack.push(new TreeNodeWrap(curNode.right));
                    }

                    if(curNode.left!=null){
                        stack.push(new TreeNodeWrap(curNode.left));
                    }
                }else{
                    retList.add(curNode.val);//visit
                }
            }
        }

        return retList;
    }
}

class TreeNodeWrap{
    public TreeNode node;
    public boolean queued;
    public TreeNodeWrap(TreeNode node){this.node = node;this.queued=false;}
}
```