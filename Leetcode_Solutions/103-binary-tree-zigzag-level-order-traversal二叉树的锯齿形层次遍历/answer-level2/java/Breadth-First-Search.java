![capture_20200304122511048.bmp](https://pic.leetcode-cn.com/018514d6adfbd00b5f9c311b076063a17fb22602b27dc9b23d6fba3d772820f6-capture_20200304122511048.bmp)
### 我的想法
因为需要一层一层地记录，所以只能选择广度优先搜索了。如何判断层与层的分隔呢？在队列中利用 null 充作哨兵。当我们的队列弹出null时，说明我们需要在队尾加入null值了（队列非空的话），为什么？

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> resultList = new LinkedList<List<Integer>>();

        if(root == null)
            return resultList;

        LinkedList<Integer> subList = new LinkedList<Integer>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null);
        boolean status = false;
        while(!queue.isEmpty()){
            TreeNode parent = queue.remove();

            if(parent == null){
                resultList.add(subList);
                if(queue.isEmpty())
                    return resultList;
                
                // 给sublist重新开辟一段存储空间
                subList = new LinkedList<Integer>();
                status = !status;
                queue.add(null);
                continue;
            }

            if(status){
                subList.addFirst(parent.val);
            }
            else{
                subList.add(parent.val);
            }
            if(parent.left != null)
                queue.add(parent.left);
            if(parent.right != null)
                queue.add(parent.right);
        }
        return resultList;
    }
}
```