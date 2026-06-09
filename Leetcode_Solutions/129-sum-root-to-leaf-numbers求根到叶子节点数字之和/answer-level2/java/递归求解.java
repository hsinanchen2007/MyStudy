### 解题思路
递归求解
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
    ArrayList<Integer> list = new ArrayList<>();
    int sum=0;
    public int sumNumbers(TreeNode root) {
        if (root == null){
            return 0;
        }
        list.add(root.val);
        if(root.left ==null && root.right==null){
            sum+=sum(list);
        }
        if(root.left!=null) sumNumbers(root.left);
        if(root.right!=null) sumNumbers(root.right);
        list.remove(list.size()-1);
        return sum;
        
    }

    public int sum(ArrayList<Integer> list){
        StringBuffer str = new StringBuffer();
        for(int i:list){
            str.append(i);
        }
        return Integer.valueOf(str.toString());
    }
}

```