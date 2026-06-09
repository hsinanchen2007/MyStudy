### 解题思路
Collections.reverse()方法
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
    public List<List<Integer>> levelOrder(TreeNode root) {
      if(root == null){return new ArrayList<List<Integer>>(0);}
        List<List<Integer>> res = new ArrayList<List<Integer>>(); //存放整个二叉树
        ArrayList<TreeNode> tempUp = new ArrayList<>();//存放上面一层节点
        ArrayList<TreeNode> tempDown = new ArrayList<>();//存放下面一层节点
        tempUp.add(root);
        boolean flag = false;
        while(tempUp.size() != 0){
            List<Integer> list = new ArrayList<>();
            for(TreeNode node:tempUp){
                list.add(node.val);
                if(node.left != null){tempDown.add(node.left);}
                if(node.right != null){tempDown.add(node.right);}
            }
            if(flag){
                Collections.reverse(list);
            }
            res.add(list);
            flag = !flag;
            tempUp.clear();
            ArrayList<TreeNode> temp = tempUp;
            tempUp = tempDown;
            tempDown = temp;
        }
        return res;  
    }
}
```