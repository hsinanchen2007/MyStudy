### 解题思路
按照102题的思路，是只有从左至右的添加元素，不符合本题在偶数行颠倒的规则，因此考虑使用栈作为中间环节的处理；同时因为偶数行的下一行仍旧是从左至右的层序遍历，因此在奇数行还是需要有从左至右的结点输出，这样才能保证下一行的结点按照左至右的顺序入队列。

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
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        Stack<Integer> stack = new Stack<>();
        queue.offer(root);
        int c = 1;
        while(!queue.isEmpty()){
            int size = queue.size();
            List<Integer> list = new ArrayList<>();
            res.add(list);
            for(int i=0; i<size; i++){
                TreeNode cur = queue.poll();       
                if(c % 2==0){
                    stack.push(cur.val);
                    if(i+1==size){
                        while(!stack.isEmpty()){
                            list.add(stack.pop());
                        }
                    }
                }else{
                    list.add(cur.val);
                }
                
                if(cur.left != null){
                    queue.offer(cur.left);
                }
                if(cur.right != null){
                    queue.offer(cur.right);
                } 
            }
            c++;
        }
        
        return res;
    }
}
```