### 解题思路
用两个ArrayList,一个保存上面一层节点，一个保存下面一层，上面一层记录下value后，清空，交换上下两层。

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
    public int[] levelOrder(TreeNode root) {
        if(root == null){return new int[]{};}
        ArrayList<Integer> res = new ArrayList<>(); //存放整个二叉树
        ArrayList<TreeNode> tempUp = new ArrayList<>();//存放上面一层节点
        ArrayList<TreeNode> tempDown = new ArrayList<>();//存放下面一层节点
        tempUp.add(root);
        while(tempUp.size() != 0){
            for(TreeNode node:tempUp){
                res.add(node.val);
                if(node.left != null){tempDown.add(node.left);}
                if(node.right != null){tempDown.add(node.right);}
            }
            tempUp.clear();
            ArrayList<TreeNode> temp = tempUp;
            tempUp = tempDown;
            tempDown = temp;
        }
        
        int[] arr = Arrays.stream(res.toArray(new Integer[res.size()])).
                    mapToInt(Integer::valueOf).toArray();
        return arr;
        
    }
}
```