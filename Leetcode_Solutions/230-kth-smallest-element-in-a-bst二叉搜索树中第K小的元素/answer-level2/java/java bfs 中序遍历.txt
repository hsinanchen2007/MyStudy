### dfs（深度优先搜索）

根据题目要求是求二叉搜索树的第k大的数，

根据二叉树的性质，可以将整个二叉树遍历一遍，把所有的结点值都存进列表中，

然后根据二叉搜索树中序遍历的特点，**中序遍历后是结点值是从小到大排列的**，所以可以直接返回列表中的第k个元素。

``` java
class Solution {
    List<Integer> res = new ArrayList<>();
    public int kthSmallest(TreeNode root, int k) {
        if(root == null)
            return 0;
        dfs(root);
        //直接返回下标为k-1的元素就是第k大的元素
        return res.get(k - 1);
    }
    //深度搜索遍历结点
    public void dfs(TreeNode root) {
        if(root == null)
            return ;
        dfs(root.left);
        //将结点值存入列表
        res.add(root.val);
        dfs(root.right);
    }
}
```
![image.png](https://pic.leetcode-cn.com/1be85195f35120f82e040e426737478530fcf3d71b020ddf844e7f4f4edd4baa-image.png)
