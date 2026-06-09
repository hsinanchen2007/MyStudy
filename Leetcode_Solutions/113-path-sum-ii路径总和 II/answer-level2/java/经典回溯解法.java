![image.png](https://pic.leetcode-cn.com/a18ff1eb9d4122f16ba19aa18e77eac30df0a8f5ccf46d070e6c966221847141-image.png)

### 解题思路
需要求出所有从根节点到叶子节点的路径，因为可能存在多条路径，因此需要回溯。
定义一个全局变量res并最终作为结果返回，使用dfs函数进行递归判断。
1、dfs函数参数定义，1）当前路径；2）当前节点node；3）当前sum
2、定义出口：1）node为null   2）递归到当前叶子节点，如果sum==node.val，则这条路径list是其中一条路径，**这里需要注意了，res.add(new ArrayList<Integer>(list)),不能直接加进去，因为list在变，最后会被覆盖；**同时需要将list remove掉，这样才能回溯；
3、【回溯经典操作】1）将node.val加入list当中 2）分别递归左子树和柚子树；3）list remove掉当前节点

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
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<Integer> tmp = new ArrayList<>();
        dfs(tmp,root,sum);
        return res;
    }
    void dfs(List<Integer> list,TreeNode node,int sum){
        //出口1
        if(node == null)
            return;
        //出口2，叶子节点
        if(node.left == null && node.right == null){
            if(node.val ==sum){
                list.add(node.val);
                res.add(new ArrayList<Integer>(list));
                list.remove(list.size()-1);
            }
            return;
        }
        list.add(node.val);
        dfs(list,node.left,sum-node.val);
        dfs(list,node.right,sum-node.val);
        list.remove(list.size()-1);
    }
}
```