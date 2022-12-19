### 解题思路
DFS+简单回溯
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
 //比上一道题而言需要保存数据
class Solution {
    List<List<Integer>> res;
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(res,new ArrayList<Integer>(),sum,root);
        return res;
    }

    /**
        res:目标返回值 所有路径的集合
        path:单挑路径
        sum:总和
        root:当前节点
    */
    public void dfs(List<List<Integer>> res,List<Integer> path,int sum,TreeNode root){
        //出口1
        if(root == null) return;
        //更新数据
        sum -= root.val;
        //出口2 判断叶子节点
        if(root.left == null && root.right == null){
            if(sum == 0){
                path.add(root.val);
                res.add(new ArrayList<Integer>(path));
                //回到上一层
                path.remove(path.size() - 1);
            }
            return;
        }

        path.add(root.val);
        dfs(res,path,sum,root.left);
        dfs(res,path,sum,root.right);
        //回到上一层
         path.remove(path.size() - 1);
    }
}
```