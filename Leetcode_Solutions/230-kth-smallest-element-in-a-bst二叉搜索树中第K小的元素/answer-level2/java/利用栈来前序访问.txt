### 解题思路
小的先访问，第k个被访问到的即是。

同样是用栈，对比官方的代码来看，我的太啰嗦了。

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
    public int kthSmallest(TreeNode root, int k) {
        if(root ==null || k<1){
            throw new IllegalArgumentException();
        }

        int retVal = root.val;

        LinkedList<TreeNodeWrapper> nodeStack = new LinkedList<TreeNodeWrapper>();
        nodeStack.addLast(new TreeNodeWrapper(root));
        TreeNodeWrapper curNodeW = null;
        TreeNode curNode = null;
        while(!nodeStack.isEmpty()){
            curNodeW = nodeStack.pollLast();
            curNode = curNodeW.node;
            if(curNode.left ==null && curNode.right==null){
                k--;
            }else{
                if(!curNodeW.selfStoredOnce){
                    if(curNode.right!=null){
                        nodeStack.addLast(new TreeNodeWrapper(curNode.right));
                    }
                    nodeStack.addLast(curNodeW);
                    if(curNode.left!=null){
                        nodeStack.addLast(new TreeNodeWrapper(curNode.left));
                    }

                    curNodeW.selfStoredOnce = true;
                }else{
                    k--;
                }
            }
            if(k==0){
                retVal = curNode.val;
                break;
            }
        }
        if(k!=0){
            throw new IllegalArgumentException();
        }

        return retVal;
    }
}
class TreeNodeWrapper{
    public TreeNode node;
    public boolean selfStoredOnce;
    public TreeNodeWrapper(TreeNode node){
        this.node = node;
        this.selfStoredOnce=false;
    }
}
```