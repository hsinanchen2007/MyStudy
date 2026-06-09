### 解题思路
用层次遍历，检查每层里是否有叶子节点，若找到，直接返回该层的层数

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
    public int minDepth(TreeNode root) {
        if(root==null)  return 0;
        int level=0;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        TreeNode p=root;
        while(!queue.isEmpty())
        {
            int n=queue.size(); //每层元素个数
            for(int i=0;i<n;i++)
            {
                p=queue.remove();
                if(p.left==null&&p.right==null)  //若为叶子节点
                {
                    return level+1;  //+1是因为实际上已经开始访问新的一层了，但level还没更新，数值为上一层的层数(level在下面更新)
                }
                if(p.left!=null)
                {
                    queue.add(p.left);
                }
                 if(p.right!=null)
                {
                    queue.add(p.right);
                }
            }
            level++;

        }
        return level;

    }
}
```