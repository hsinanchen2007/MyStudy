### 解题思路
![image.png](https://pic.leetcode-cn.com/1e1b02083d1651528ab74b9b02d5cd3a09c4ea78eb3c5af881138f3005d8b98f-image.png)

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        HashMap<TreeNode, TreeNode> parentMap = new HashMap<>();
        parentMap.put(root,null);
        LinkedList<TreeNode> stack = new LinkedList<>();
        // stack.addFirst(root);
        while(root != null){
            stack.addFirst(root);
            parentMap.put(root.left, root);
            root = root.left;
        }
        // 先序遍历
        while(stack.size() != 0){
            root = stack.removeFirst();
            // 如果有右节点，则把右节点的所有左子节点都一下子全部压入栈中
            if(root.right != null){
                parentMap.put(root.right,root);
                TreeNode tmp = root.right;
                while(tmp != null){
                    stack.addFirst(tmp);
                    parentMap.put(tmp.left,tmp);
                    tmp = tmp.left;
                }
            }
        }

        HashSet<TreeNode> parentSet = new HashSet<>();
        while(p != null){
            parentSet.add(p);
            p = parentMap.get(p);
        }
        while(parentSet.contains(q) == false){
            q = parentMap.get(q);
        }
        
        return q;
    }
}
```