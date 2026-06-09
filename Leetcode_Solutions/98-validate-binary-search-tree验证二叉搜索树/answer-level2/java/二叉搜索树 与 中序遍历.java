### 解题思路
二叉搜索树中序遍历是一个有序数组。然后根据数组顺序遍历，如果不是顺序那么肯定就不是二叉搜索树。反之则反。

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
    private List<Integer> list;
    
    public void midorder(TreeNode node){
        if(node == null)
            return;
        midorder(node.left);
        list.add(node.val);
        midorder(node.right);
    }

    public boolean isValidBST(TreeNode root) {
        this.list = new ArrayList<>();
        midorder(root);
        for(int i = 0; i < list.size() - 1; i++){
            if(list.get(i) >= list.get(i+1))
                return false;
        }
        return true;
    }
}
```