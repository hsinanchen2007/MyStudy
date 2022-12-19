### 解题思路
在102的基础上加上一个逆置列表的操作。
其实还可以在
if(node.left != null)
    nodes.add(node.left);
if(node.right != null)
    nodes.add(node.right);
这里反过来添加，先加right，在加left。

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
        if(root == null)
            return new ArrayList<>();

        Queue<TreeNode> queue = new LinkedList<>();
        List<List<Integer>> lists = new ArrayList<>();
        
        queue.offer(root);
        int flag = 0;

        while(!queue.isEmpty()){
            List<Integer> vals = new ArrayList<>();
            List<TreeNode> nodes = new ArrayList<>();
            while(!queue.isEmpty()){
                TreeNode node = queue.poll();
                if(node.left != null)
                    nodes.add(node.left);
                if(node.right != null)
                    nodes.add(node.right);
                vals.add(node.val);
            }
            if(flag % 2 == 1){
                for(int i = 0; i < vals.size() / 2; i++){
                    int tmp = vals.get(i);
                    vals.set(i, vals.get(vals.size()-1-i)) ;
                    vals.set(vals.size()-1-i, tmp);
                }
            }
            lists.add(new ArrayList<>(vals));
            flag += 1;
            while(nodes.size() != 0){
                queue.offer(nodes.get(0));
                nodes.remove(0);
            }
        }
        return lists;
    }
}
```