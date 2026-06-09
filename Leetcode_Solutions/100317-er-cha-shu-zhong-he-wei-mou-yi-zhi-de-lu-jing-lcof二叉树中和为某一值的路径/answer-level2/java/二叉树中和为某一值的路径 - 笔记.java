### 解题思路
采用先序遍历，然后中序遍历过程中统计当前是否总数为sum，如果是则记录下来

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
     /**
    * 采用先序遍历，然后中序遍历过程中统计当前是否总数为sum，如果是则记录下来
    **/
    List<Integer> list = new ArrayList<>();
    List<List<Integer>> lists = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null) {
            return new ArrayList<> ();
        }
        recur(root, sum);

        return lists;
    }

    private void recur(TreeNode root, int sum) {
        if(root == null){
            return;
        }
        list.add(root.val);
        sum -= root.val;
        // 当sum递减为0的时候，并无左右节点，则保存当前结果（因为题目要求的根节点->叶子节点）
        if(root.left == null && root.right == null && sum == 0){
            lists.add(new ArrayList(list));// new ArrayList为了创建一个新对象
            // 当前节点往上退一步，然后下面的接着继续用[5, 4,......]
            list.remove(list.size() - 1);
            return;
        }
        recur(root.left,sum);
        recur(root.right,sum);
        // 移除最新放进来的那个
        list.remove(list.size() - 1);
    }
}
```