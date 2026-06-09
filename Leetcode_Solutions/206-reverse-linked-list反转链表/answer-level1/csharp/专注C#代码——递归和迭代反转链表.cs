**专注C#的学习**

数据结构
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
```
递归方法

```

public class Solution {
    public ListNode ReverseList(ListNode head) {  
        //递归     
        if(head==null||head.next==null)return head;
        ListNode p = ReverseList(head.next);
        head.next.next = head;//链接新节点
        head.next = null;//断开当前节点的原后续节点
        return p;
    }
}
```
迭代方法
```

public class Solution {
    public ListNode ReverseList(ListNode head) {
        //迭代
        ListNode p = head;
        ListNode result = new ListNode(0);
        while(p!=null){
            ListNode s = new ListNode(p.val);
            s.next = result.next;
            result.next = s;
            p=p.next;
        }
         return result.next;
    }
}
```

