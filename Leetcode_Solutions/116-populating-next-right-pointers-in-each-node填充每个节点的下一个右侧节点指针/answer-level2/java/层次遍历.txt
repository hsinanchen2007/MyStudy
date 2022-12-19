申请一个队列用于保存树节点，为了提前获得并保存Node,next的值，采用从右往左的层次遍历；用一个变量记录当前层的最大节点数，一个变量记录正在访问的当前层的第几个节点。
class Solution {
    public Node connect(Node root) {
        if (root==null){
            return null;
        }
         Queue<Node> queue=new LinkedList<>();
        root.next=null;
        int maxnode=2;
        int k=maxnode;
        Node prenode=new Node();
        if (root.right!=null){
            queue.offer(root.right);
        }
        if (root.left!=null){
            queue.offer(root.left);
        }
        while (!queue.isEmpty()){
            Node node=queue.poll();
            if (node.right!=null){
                queue.offer(node.right);
            }
            if (node.left!=null){
                queue.offer(node.left);
            }
            if (k==maxnode){
                node.next=null;
                k--;
                prenode=node;
            }else if (k<maxnode){
                if (k==1){
                    node.next=prenode;
                    maxnode*=2;
                    k=maxnode;
                }else {
                    node.next=prenode;
                    k--;
                    prenode=node;
                }
            }
            
        }
        return root;
    }
}