![l.png](https://pic.leetcode-cn.com/179c7feb9517f875880fe2e4897c72e8d552403390f499042e40a379533f9064-l.png)


### 解题思路
如果两个链表有其中一个为空，返回另一个；

对两个链表从头开始遍历，每到一个节点，比较两个链表节点的大小，节点值小的节点合并到新链表并向下移动一个，直到两个链表遍历完

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null){
            return l2;
        }
        if(l2==null){
            return l1;
        }
        ListNode ans=new ListNode(0);
        ListNode p=ans;
        while(l1!=null||l2!=null){
            int v1=l1==null?Integer.MAX_VALUE:l1.val;
            int v2=l2==null?Integer.MAX_VALUE:l2.val;
            if(v1<v2){
                p.next=new ListNode(v1);
                l1=l1==null?null:l1.next;
            }else{
                p.next=new ListNode(v2);
                l2=l2==null?null:l2.next;
            }
            p=p.next;
        }
        return ans.next;
    }
}
```