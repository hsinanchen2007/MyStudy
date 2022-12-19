![image.png](https://pic.leetcode-cn.com/8a89ae7cfe2c4fe03accb000f2729c2445305f0dac125426d4ef96c6b4e40b5e-image.png)



class Solution {

    LinkedList<Node> list =new LinkedList<Node>();
    Node pre = null;
    Node first=null;
    Node last=null;
    public Node treeToDoublyList(Node root) {
 
        if(root==null) return root;
        getOrder(root);
        last=pre;
        last.right=first;
        first.left=last;
        return first;
    }
    
    
        public void getOrder(Node cur){
        if(cur!=null){
        if(cur.left!=null){
            getOrder(cur.left);//左
        }
        if(first==null) {
            first=cur;
            pre=cur;
        }else{
            pre.right=cur;//上一个结点的right
            cur.left=pre;//cur的left就是pre
            pre=cur;//pre就边成当前结点
        }
        
        if(cur.right!=null){
            getOrder(cur.right);
        }
        }
    }