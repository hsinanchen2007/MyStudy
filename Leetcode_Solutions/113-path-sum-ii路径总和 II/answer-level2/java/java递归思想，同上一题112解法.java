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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
         List<List<Integer>> list=new ArrayList<>();
         List<Integer> tmpList=new ArrayList<>();
         dfs(root,sum,list,tmpList);
         return list;
    }
    public void dfs(TreeNode node,int sum, List<List<Integer>> list,List<Integer> tmpList){
        // 递归退出的条件
        if(node==null)return ;
        tmpList.add(node.val);
        sum-=node.val;
        // 遍历的叶子节点的时候
        if(node.left==null&&node.right==null){
            if(sum==0){
                list.add(new ArrayList<>(tmpList));
            }
        }
        if(node.left!=null){
            dfs(node.left,sum,list,tmpList);
        }
        if(node.right!=null){
            dfs(node.right,sum,list,tmpList);
        }
        // 这个一定要加，类似于把上一层遍历结束后，把tmpList的最后一位给它移出去，返回到上一层把右节点放进去看是否满足
        tmpList.remove(tmpList.size()-1);
    }
}
```