### 解题思路
![微信图片_20200328191314.jpg](https://pic.leetcode-cn.com/6fe7b4455f376cfbf228644655f48918198d37a91db128901007fa00703f6999-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200328191314.jpg)
此处撰写解题思路

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
    //迭代解法
    public ListNode reverseList_v1(ListNode head) {
        ListNode r = null;
        ListNode p = head;
        ListNode q = null;
        while(p != null){
            r = q;
            q = p;
            p = p.next;
            q.next = r;
        }
        head = q;
        return head;
    }

    //递归解法
    public ListNode reverseList(ListNode head){
        if(head == null) return null;
        ListNode newHead = head;
        while(newHead.next != null){
            newHead = newHead.next;
        }
        if(head.next == null) return head;
        subReverse(head,head.next);
        return newHead;
    }
  

    public ListNode subReverse(ListNode cur,ListNode next){
        //当下一个位置上为null时，掉换顺序
        if(next.next == null){
            next.next = cur;
            cur.next = null;
            return cur;
        }
        return subReverse(cur,subReverse(next,next.next));
    }
    
}
```