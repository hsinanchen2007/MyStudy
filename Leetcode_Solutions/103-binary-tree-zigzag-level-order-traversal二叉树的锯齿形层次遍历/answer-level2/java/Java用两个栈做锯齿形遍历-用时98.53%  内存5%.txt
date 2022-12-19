### 解题思路
用了两个栈，一个栈current用来输出当前层顺序，一个栈next用来存储下一层节点，需要一个变量lefttoright记录当前是从左往右还是从右往左，决定了需要先插入左子节点还是右子节点，每一层遍历完时，做存入结果list,将lefttoright取反，交换两个栈(让next栈为空)三个操作。
基本还是中序遍历的变体。


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
        Stack<TreeNode> current=new Stack<TreeNode>();
        Stack<TreeNode> next=new Stack<TreeNode>();
        boolean lefttoright=true;
        List<List<Integer>> res=new ArrayList<>();
        if(root==null) return res;
        current.push(root);
        List<Integer> list=new ArrayList<Integer>();
        while(!current.isEmpty()){
            TreeNode node=current.pop();
            list.add(node.val);    
            if(lefttoright){
                if(node.left!=null){
                    next.push(node.left);
                }   
                if(node.right!=null){
                    next.push(node.right);
                }
            }
            if(!lefttoright){
                if(node.right!=null){
                    next.push(node.right);
                }   
                if(node.left!=null){
                    next.push(node.left);
                }
            }            
            if(current.isEmpty()){
                res.add(new ArrayList<Integer>(list) );
                list.clear();
                lefttoright=!lefttoright;
                Stack<TreeNode> temp=new Stack<>();
                temp=current;
                current=next;
                next=temp;
            }
        }
        return res;
    }
}
```