### 解题思路
1 利用队列进行层序遍历，遍历每一层节点。
2 每一层节点，都创建一个头节点，把每一层的值都连接，变成链表。
3 然后利用ArrayList 在存储每一层的头结点。

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
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(tree);
        ArrayList<ListNode> ans=new ArrayList();
        while(!queue.isEmpty())
        {
           
            ListNode head=new ListNode(0);
            ListNode p=head;
            int level=0;
            int size=queue.size();
            TreeNode node;
            while(level<size)
            {
                node=queue.poll();
                p.next=new ListNode(node.val);
                p=p.next;
                level++;
                if(node.left!=null)
                    queue.add(node.left);
                if(node.right!=null)
                    queue.add(node.right);
            }
            ans.add(head.next);
        }
        ListNode[] list=new ListNode[ans.size()];
        for(int i=0;i<ans.size();i++)
            list[i]=ans.get(i);
        return list;
    }
}
```