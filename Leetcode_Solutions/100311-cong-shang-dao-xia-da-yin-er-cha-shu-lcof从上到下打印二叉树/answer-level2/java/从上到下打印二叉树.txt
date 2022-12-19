### 解题思路
    本题是一个经典的二叉树层序遍历问题，需要用到队列这种数据结构。在Java语言中可以先建立一个列表存放遍历到的节点。最后再将列表转化为数组。list[i]这种写法是错误的，需要些list.get(i)。另外，如果新建一个空数组，不存储任何元素可以 new int []={}
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
    public int[] levelOrder(TreeNode root) {
        List<Integer> list=new ArrayList<>();
        if(root==null)
            return new int[]{};
        Queue <TreeNode> queue=new LinkedList<TreeNode>();  //构建一个二叉树队列
        queue.add(root);
        while(!queue.isEmpty())
        {
            int size=queue.size();
            while(size>0)
            {
                TreeNode node=queue.remove();
                list.add(node.val);
                if(node.left!=null)
                    queue.add(node.left);
                if(node.right!=null)
                    queue.add(node.right);
                size--;
            }
        }
        int [] res=new int[list.size()];
        for(int i=0;i<res.length;i++)
            res[i]=list.get(i);
        return res;
    }
}
```