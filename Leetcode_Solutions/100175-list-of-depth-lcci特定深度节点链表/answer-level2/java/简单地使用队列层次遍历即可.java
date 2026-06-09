### 解题思路
此处撰写解题思路
![捕获7.PNG](https://pic.leetcode-cn.com/bdfa19d4b7fe2a17f59d0f90dbe016aa9141b65ab009bc2ac59f090a99bdf400-%E6%8D%95%E8%8E%B77.PNG)

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
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int Depth(TreeNode root){
        if(root==null){
            return 0;
        }
        return Math.max(Depth(root.left),Depth(root.right))+1;
    }
    public ListNode[] listOfDepth(TreeNode tree) {
        int depth=Depth(tree);
        int i=0;
        Queue<TreeNode> queue=new LinkedList<>();
        ListNode[] lists=new ListNode[depth];
        queue.add(tree);
        while(!queue.isEmpty()&&i<depth){
            int size=queue.size();
            ListNode head=new ListNode(-1);
            ListNode p=head;
            while(size>0){
                TreeNode node=queue.poll();
                ListNode listnode=new ListNode(node.val);
                p.next=listnode;
                p=p.next;
                if(node.left!=null){
                    queue.add(node.left);
                }
                if(node.right!=null){
                    queue.add(node.right);
                }
                size--;
            }
            lists[i]=head.next;
            i++;
        }
        return lists;
    }
}

























```