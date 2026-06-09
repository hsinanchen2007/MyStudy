将二叉树展开为链表，可以视为二叉树的先序遍历。
先序遍历采用启发方法，较为通用。
```
class Solution {
    //指示类
    class G{
        //guide : 0=>operation，1=>visit child
        public int guide;
        public TreeNode node;
        public G(int g,TreeNode n){
            this.guide = g;
            this.node = n;
        }
    }
    public void flatten(TreeNode root) {
        TreeNode p = new TreeNode(-1);
        //遍历栈
        Stack<G> stack = new Stack<>();
        //访问根节点
        stack.push(new G(1,root));
        while(!stack.isEmpty()){
            G g = stack.pop();
            if(g.node == null) continue;
            if(g.guide == 1){
                // visit child-right
                stack.push(new G(1,g.node.right));
                // visit child-left
                stack.push(new G(1,g.node.left));
                //operation 
                stack.push(new G(0,g.node));
                //根据栈的性质，先入后出
            }
            else{
                p.left = null;
                p.right = g.node;
                p = p.right;
                System.out.print(g.node.val+",");
            }
        }
    }
}
```
