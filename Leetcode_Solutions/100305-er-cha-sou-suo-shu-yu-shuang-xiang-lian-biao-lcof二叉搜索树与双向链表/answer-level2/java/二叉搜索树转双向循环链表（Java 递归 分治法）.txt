虽然该题用递归遍历会相对来说简单点，但是本人更喜欢使用分治法的思想来解题，如果理解好分治法，它会使代码思路更清晰。

首先考虑整棵树的结果=左子树转成的双向链表+root+右子树转成的双向链表，合并的过程要知道：左子树双向链表中最后一个节点 和 右子树双向链表中第一个节点，那么我们递归函数的返回类型应该是包含每个合并链表的第一个节点和最后一个节点，所以我定义了返回类 ResultType(Node first,Node last)。
代码思路：
1.主函数调用helper函数（递归函数）
2.递归函数内部：
  2.1 divide 先递归左子树得到左边双向链表，再递归右子树得到右边双向链表
  2.2 conquer 合并链表 
3.将结果首尾相接，返回第一个节点


代码：

class Solution {
     
    class ResultType{
        public Node first,last;
        ResultType(Node first,Node last){
            this.first=first;
            this.last=last;
        }
    }
    public Node treeToDoublyList(Node root){
        if(root==null){
            return null;
        }
        ResultType result = helper(root);
        result.first.left=result.last;
        result.last.right=result.first;

        return result.first;
        
    }
    public ResultType helper(Node root){
        if(root==null){
            return null;
        }
        //divided
        ResultType left_tree=helper(root.left); // (1,3) : 1<->2<->3
        ResultType right_tree=helper(root.right);//(5,5) : 5
        
        Node node = new Node(root.val); // 4
        ResultType result = new ResultType(null,null);
        
        //1<->2<->3<->4
        if(left_tree==null){
            result.first=node;
        }else{
            result.first=left_tree.first;
            left_tree.last.right=node;
            node.left=left_tree.last;
        }
        //4<->5
        if(right_tree==null){
            result.last=node;
        }else{
            result.last=right_tree.last;
            right_tree.first.left=node;
            node.right=right_tree.first;
        }
        return result;
    }

}
