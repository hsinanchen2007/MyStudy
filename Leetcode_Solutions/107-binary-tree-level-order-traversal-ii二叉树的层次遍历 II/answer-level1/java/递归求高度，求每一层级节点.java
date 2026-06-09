### 解题思路
此处撰写解题思路

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
public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new LinkedList<>();
        int height = getHeight(root);
        for(int i=height;i>0;i--){
            List<Integer> temp = new LinkedList<>();
            getLevelNode(i,root,temp);
            result.add(temp);
        }
        return result;
    }

    int getHeight(TreeNode root){
        if(root==null){
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        return Math.max(leftHeight,rightHeight)+1;
    }

    void getLevelNode(int level,TreeNode root,List<Integer> list){
        if(root==null){
            return;
        }
        if(level==1){
            list.add(root.val);
        }else{
            getLevelNode(level-1,root.left,list);
            getLevelNode(level-1,root.right,list);
        }
    }
}
```