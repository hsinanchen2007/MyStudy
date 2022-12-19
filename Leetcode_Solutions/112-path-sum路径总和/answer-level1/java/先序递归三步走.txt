### 解题思路
## preorder
## 把二叉树节点分为：普通节点，叶子节点
## 普通节点：1.有左右节点；2.左右节点其中一个为空
## 叶子节点：左右节点均为空

### 1.先序遍历二叉树，判空后执行sum-=root.val
### 2.如果sum=0，判断该节点类型：普通节点 or 叶子节点
### 2.1.1:先判断该节点是否是叶子节点——叶子结点.左右=null
### 2.1.2:是叶子节点，返回true
### 3：不是叶子节点——无视sum=0条件，继续递归

![image.png](https://pic.leetcode-cn.com/b74689f7dcf8bc167bb3abbf925704291ca522e1a849949ba1eb5e412bddb384-image.png)



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
    
      //通过布尔值来判断
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)return false;
        sum-=root.val;
        if(sum==0)
            if(root.left==null&&root.right==null)
                return true;
        return hasPathSum(root.left,sum)||hasPathSum(root.right,sum);
    }    




    //通过值来判断
    public int recursiveHasPathSum(TreeNode root, int currSum,int sum){
        // null
        if(root==null)return 0;

        //all nodes
        currSum+=root.val;
        int sumL = recursiveHasPathSum(root.left,currSum,sum);
        int sumR = recursiveHasPathSum(root.right,currSum,sum);
        if(root.left==null&&root.right==null)return currSum;
        if(root.left==null)
            return sumR;
        if(root.right==null)
            return sumL;
        if(sumL==sum||sumR==sum)return sum;
        return Math.max(sumL,sumR);
        
        
    }

  
}
```