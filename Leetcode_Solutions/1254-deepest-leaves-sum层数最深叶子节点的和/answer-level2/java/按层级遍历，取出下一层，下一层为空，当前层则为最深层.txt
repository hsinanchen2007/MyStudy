### 解题思路
![image.png](https://pic.leetcode-cn.com/e632af8de7c1b590b0d6514e87804ee549df6958eb4c22d12020415b27afd1be-image.png)

按层级遍历，取出下一层，下一层为空，当前层则为最深层

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
    public int deepestLeavesSum(TreeNode root) {
        
        if(root == null){
            return 0;
        }

        List<TreeNode>  roots = new ArrayList<>();
        roots.add(root);

        //层序尾递归遍历
        return deepestLeavesSum(roots);
    }

    public int deepestLeavesSum(List<TreeNode> roots) {
        
        if(roots == null ||  roots.size() <=0){
            return 0;
        }

        //保存下一层级
        List<TreeNode>  nextList = new ArrayList<>();
        
        //当前层级总和
        int sum  = 0;
        //遍历当前层级
        for (TreeNode node  : roots) {
            
            if(node.left != null){
                //加入下一左层级
                nextList.add(node.left);
            }

            if(node.right != null){
                //加入下一右层级
                nextList.add(node.right);
            }

            //计算当前层级总和
            sum += node.val;
        }
        
        //若果下一层级为空，当前层级就是最深层级
        if(nextList.size()<=0){
            return sum;
        }
        
        return  deepestLeavesSum(nextList);
    }
    
}
```