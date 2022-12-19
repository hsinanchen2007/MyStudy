### 解题思路
注释

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
        if (tree==null)//如果根节点是空，则返回空数组
            return new ListNode[0];
        Queue<TreeNode> queue=new LinkedList<>();//用来存放中间操作的队列
        queue.add(tree);
        List<ListNode> list =new ArrayList<>();
        int size=1;//记录上一行的数目
        ListNode start=new ListNode(0),find=start;//start是要加入数组的链表头结点的上一个节点，find是一个指针
        while (queue.size()>0){
            if (size>0) {//当目前操作还没有达到上层节点的数目时。表示的是还在操作同一层的节点
                size--;//维护剩余数目
                TreeNode head = queue.poll();//从队列拿出即将操作的节点，为最上层最左节点
                find.next=new ListNode(head.val);//放入链表最后
                find=find.next;//维护链表指针
                if (head.left != null)//维护队列
                    queue.add(head.left);
                if (head.right != null)
                    queue.add(head.right);
            }
            else{//上一层的所有节点已经完全从队列剥离
                list.add(start.next);//把链表加入list
                size=queue.size();//维护新的size
                start=new ListNode(0);//维护链表头
                find=start;//维护指针
            }
        }
        list.add(start.next);//上面循环在最后一个队列出栈后，没有加入，这里补上
        ListNode[] res=new ListNode[list.size()];//把list转数组
        int j=0;
        for (ListNode i:list){
            res[j++]=i;
        }
        return res;
    }
}
```