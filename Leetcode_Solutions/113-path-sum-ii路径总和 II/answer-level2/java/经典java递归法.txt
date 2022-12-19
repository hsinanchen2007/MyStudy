### 解题思路
此处撰写解题思路
全局变量List subList
subList.remove(subList.size()-1)这个很关键。
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
    List<List<Integer>> List = new ArrayList<>();
    List<Integer> subList = new ArrayList<Integer>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root == null)
            return List;
        helper(root,sum);
        return List;
    }
    public void helper(TreeNode root , int sum){
        sum = sum - root.val;
        subList.add(root.val);
        if(root.left == null && root.right == null){
            if(sum == 0)
                List.add(new ArrayList<>(subList));
        }
        if(root.left != null){
            pathSum(root.left,sum);
        }
        if(root.right != null)
            pathSum(root.right,sum);
        subList.remove(subList.size()-1);
    }

}
```