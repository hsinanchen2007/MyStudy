### 解题思路
层序遍历，往队列中添加元素时如果碰到null，就往队列中加null。每次循环都判断当前层的list是否满足镜像，要注意null节点需要随便给list中填个数，否则过不了两个右子树val一样的情况。想是好想，写起来不行，性能也不好。

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
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
            return true;
        }
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);
        while(!queue.isEmpty()){
            int size = queue.size();
            List<Integer> first = new ArrayList();
            for(int i=0;i<size;i++){
                TreeNode node = queue.remove();
                if(node == null){
                    first.add(-1);
                    continue;
                }else{
                    first.add(node.val);
                }
                if(node.left!=null){
                    queue.add(node.left);
                }else{
                    queue.add(null);
                    
                }
                if(node.right!=null){
                    queue.add(node.right);
                }else{
                    queue.add(null);
                   
                }
            }
            int length = first.size();
            for(int i=0;i<length/2;i++){
                if(first.get(i)!=first.get(length-i-1)){
                    return false;
                }
            
            }
        }
        return true;
    }
}
```