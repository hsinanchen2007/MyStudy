### 解题思路
此题标准的DFS+回溯法，思路如下：
主函数：
1.初始化res和path的LinkedList
2.调用DFS
3.返回res
DFS：（根节点，当前值）
1.判断是否空，是就退出递归
2.将根节点加入路径中
3.更新当前值：sum-root.val
4.判断找到路径的条件：1.root为叶子节点2.sum=0，就将路径加入path
5.回溯，将路径中的最后一个节点删除，且返回父节点，所以用了removeLast函数（PS此处不需要sum+root.val的原因是回溯之后退回上层递归，此时的sum还是调用递归时候的sum，所以不需要变）

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
    LinkedList<List<Integer>> res=new LinkedList<>();
    LinkedList<Integer> path=new LinkedList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        dfs(root,sum);
        return res;
    }
    void dfs(TreeNode root,int sum){
        if(root==null)return;
        path.add(root.val);
        sum=sum-root.val;
        if(root.left==null&&root.right==null&&sum==0)res.add(new LinkedList(path));
        dfs(root.left,sum);
        dfs(root.right,sum);
        int node=path.removeLast();     
    }
}
```