`

```python []
class Node(object):
    def __init__(self,y_money,n_money):
        self.y_money=y_money  //偷这一家
        self.n_money=n_money  //不偷这一家
        
class Solution(object):
    def rob(self, root):
        cur=self.process(root)
        return max(cur.y_money,cur.n_money)
        
    def process(self,root):
        if not root:
            return Node(0,0)   //如果为空则表示没偷盗前，返回（0，0）
        left=self.process(root.left)   //递归生成左孩子的结构体
        right=self.process(root.right)   //递归生成右孩子的结构体
        y_money=root.val+left.n_money+right.n_money   //偷当前节点所能获得的金额
        n_money=max(left.n_money,left.y_money)+max(right.n_money,right.y_money)  //不偷当前节点所能获得的金额
        return Node(y_money,n_money)
```
```java []
class Solution {
    class Node{
        int y_money;
        int n_money;
        public Node(int y_money, int n_money) {
            this.y_money = y_money;
            this.n_money = n_money;
        }
    }

    public int rob(TreeNode root) {
        Node cur=process(root);
        return Math.max(cur.y_money,cur.n_money);
    }
    public Node process(TreeNode root){
        if (root==null) return new Node(0,0);
        Node left=process(root.left);
        Node right=process(root.right);
        int y_money=root.val+left.n_money+right.n_money;
        int n_money=Math.max(left.y_money,left.n_money)+Math.max(right.y_money,right.n_money);
        return  new Node(y_money,n_money);
    }
}
```
