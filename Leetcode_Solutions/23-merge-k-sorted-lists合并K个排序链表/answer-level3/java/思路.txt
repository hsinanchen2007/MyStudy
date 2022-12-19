### 解题思路
此处撰写解题思路
我的思路:
    首先创建一个新的链表，其次就是一个辅助这个新的链表的节点，另外一个是用来辅助数组链表中的值的！
再便利链表的长度，再循环里面挨个便利当前链表中的元素，将元素都存放到辅助新链表的节点上，将这几个数组的
链表都放入到新的链表上了之后
我们再进行排序，对这个链表进行了一次选择排序的算法u，效率不是很高！
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode temp=new ListNode(-9999999);
        ListNode cur=temp;
        ListNode next=null;
        for(int i=0;i<lists.length ;i++){
            if(lists[i]!=null){
            while(lists[i]!=null){
                    next=lists[i].next;
                    lists[i].next=cur.next;
                    cur.next=lists[i];
                    lists[i]=next;
                }
            }
        }
        while(cur!=null){
            ListNode c=cur.next;
            while(c!=null){
                if(cur.val > c.val){
                    int k=cur.val;
                    cur.val=c.val;
                    c.val=k;
                }
                c=c.next;
            }
            cur=cur.next;
        }
        return temp.next;
    }
}
```