

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
    public int sumEvenGrandparent(TreeNode root) {
        int result = 0;
        //定义两个栈，一个不断的存取祖父节点，另一个存储所有符合祖父节点偶数的节点
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        if(root == null){
            return 0;
        }
        
        TreeNode temp = root;
        stack1.push(temp);
        while(!stack1.isEmpty()){
            temp = stack1.pop();
            if(null!=temp.left){
                if(null!=temp.left.left){
                    if(temp.val%2==0){
                        stack2.push(temp.left.left);
                    }
                }
                if(null!=temp.left.right){
                    if(temp.val%2==0){
                        stack2.push(temp.left.right);
                    }
                }
                if(null!=temp.left.right||null!=temp.left.left){
                    stack1.push(temp.left);
                }
            }
            
            if(null!=temp.right){
                if(null!=temp.right.left){
                    if(temp.val%2==0){
                        stack2.push(temp.right.left);
                    }
                }
                if(null!=temp.right.right){
                    if(temp.val%2==0){
                        stack2.push(temp.right.right);
                    }
                }
                if(null!=temp.right.right||null!=temp.right.left){
                    stack1.push(temp.right);
                }
            }
            
        }
        while(!stack2.isEmpty()){
            result+=stack2.pop().val;
        }
        return result;
    }

}

```
