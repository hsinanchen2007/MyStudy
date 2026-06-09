### 解题思路
思路就是将每个节点入队，一层以null结尾，出队的时候，将出队元素赋值给上一个出队元素的next，直到队列为空

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Queue<Node> queue=new LinkedList();
        if(root==null){
            return null;
        }
        queue.offer(root);
        queue.offer(null);
        Node pre=null;
        while(queue.size()>0){
            Node cur=queue.poll();
            if(cur!=null){//当前为树节点
                if(cur.left!=null){//非叶子节点左右孩子入栈
                    queue.offer(cur.left);
                    queue.offer(cur.right);
                }
            }else if(queue.size()>0){//null节点并且队列不为空则标志下一层
                queue.offer(null);
            }
            if(pre!=null){//将上一个树节点的next设置为当前节点
                pre.next=cur;
            }
            pre=cur;
        }
        return root;
    }
}
```