### 解题思路
    此题类似二叉树的锯齿形层次遍历，新引入一个变量记录打印到了第几行。分奇数行和偶数行决定在列表中的哪一个位置添加元素。

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res=new ArrayList<>();
        if(root==null)
            return res;
        Queue <TreeNode> queue=new LinkedList<TreeNode> ();
        queue.add(root);
        int flag=0;
        while(!queue.isEmpty())
        {
            int size=queue.size();
            List<Integer> list=new ArrayList<>();
            while(size>0)
            {
                TreeNode node=queue.remove();
                //此处的解法类似于二叉树的锯齿形层次遍历
                if(flag%2==0)
                {
                    list.add(node.val);
                }
                else
                {
                    list.add(0,node.val);
                }
                if(node.left!=null)
                    queue.add(node.left);
                if(node.right!=null)
                    queue.add(node.right);
                size--;
            }
            res.add(list);
            flag++; //这里才是循环过了一行。
        }
        return res;
    }
}
```