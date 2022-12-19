### 解题思路
1.定义两个队列，queue放本层的节点，queue2放queue中所有节点的子节点。
2.遍历完一层后，将两个队列都往下更新一层。

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
         List<List<Integer>> list = new ArrayList<List<Integer>>();
        if(root == null)
            return list;
        
        Queue<TreeNode> queue = new LinkedList<>();
        Queue<TreeNode> queue2 = new LinkedList<>();//用来存每一层的节点
        //添加根节点
        queue.add(root);
        List<Integer> l = new ArrayList<Integer>();
        l.add(root.val);
        list.add(l);    
        if(root.left!=null)
            queue2.add(root.left);
        if(root.right!=null)
            queue2.add(root.right);

        while(!queue2.isEmpty()){
            List<Integer> arrayList = new ArrayList<Integer>();
            queue.clear();
            while(!queue2.isEmpty()){
                TreeNode temp = queue2.poll();
                queue.add(temp);
                arrayList.add(temp.val);
            }
            list.add(arrayList);

            for(TreeNode n : queue){
                if(n.left!=null)
                    queue2.add(n.left);
                if(n.right!=null)
                    queue2.add(n.right);
            }
        }

        return list;
    }
}
```