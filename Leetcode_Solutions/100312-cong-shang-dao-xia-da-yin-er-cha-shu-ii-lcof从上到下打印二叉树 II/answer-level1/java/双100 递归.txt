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
    private List<List<Integer>> list =new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        helper(root,0);
        return list;
    }
    private void helper(TreeNode node,int index){//index记录树的深度
        if (node==null)
            return;
        if (index==list.size()) {//如果深度超出了list的size，就说明到了最新的深度
            List<Integer> mid = new ArrayList<>();
            mid.add(node.val);
            list.add(mid);
        }
        else{//若没超出，则添加到已有的深度
            List<Integer> mid = list.get(index);
            mid.add(node.val);
            list.set(index,mid);
        }
        helper(node.left,index+1);//继续递归
        helper(node.right,index+1);
    }
}
```