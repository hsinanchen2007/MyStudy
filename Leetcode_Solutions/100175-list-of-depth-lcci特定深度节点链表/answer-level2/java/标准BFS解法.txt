### 解题思路
此处撰写解题思路

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
    public ListNode[] listOfDepth(TreeNode tree) {
        List<ListNode> list = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(tree);
        while(!queue.isEmpty()){
            int size = queue.size();
            // for(int i =0; i < size;i++){
            
            ListNode head = new ListNode(0);
            ListNode cur = head;
            while(size-->0){
                TreeNode treeNode = queue.poll();
                ListNode listNode = new ListNode(treeNode.val);
                cur.next = listNode;
                cur = cur.next;
                if(treeNode.left!=null)
                    queue.offer(treeNode.left);
                if(treeNode.right!=null)
                    queue.offer(treeNode.right);
            }    
            list.add(head.next);   
            
            // }
        }
        return list.toArray(new ListNode[0]);
    }
}
```