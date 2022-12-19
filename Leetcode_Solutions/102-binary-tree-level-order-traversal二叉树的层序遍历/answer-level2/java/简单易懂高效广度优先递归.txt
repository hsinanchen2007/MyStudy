### 解题思路


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
        
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root == null) return result;
        result.add(new ArrayList<Integer>());
        result.get(0).add(root.val);
        bfs(root.left, root.right, result, 1);
        return result;
    }

    public void bfs(TreeNode left,TreeNode right, List<List<Integer>> result, int index){
        //创建新层对应列表
        if (result.size() <= index) result.add(new ArrayList<Integer>());  
        //添加元素
        if (left != null) result.get(index).add(left.val);
        if (right != null) result.get(index).add(right.val);
        //当这一层没有元素时，删除列表
        if (result.get(index).size() == 0) result.remove(index);
        //递归结束
        if (left == null && right == null) {
            return;
        //左子树遍历完成
        }else if (left == null) {
            bfs (left, right.left,result,index+1);
            bfs (left, right.right,result,index+1);
        //右子树遍历完成
        }else if (right == null){
            bfs (left.left, right,result,index+1);
            bfs (left.right, right,result,index+1);
        }else {
            bfs (left.left, null,result,index+1);
            bfs (left.right, null,result,index+1);
            bfs (null, right.left,result,index+1);
            bfs (null, right.right,result,index+1);
        }

       
        

    }
}
```