### 解题思路
![QQ截图20200401142756.png](https://pic.leetcode-cn.com/4dbea99528dfb1ecda22f7950a10a32ba715d3ea15c53af9f1bc191c9b0981cc-QQ%E6%88%AA%E5%9B%BE20200401142756.png)
0.过滤条件：任一链表为空时返回另一条链表。
解题思路：1.先选择头结点最小的那一条作为主链
2.移动主链的指针，用副链的头结点往主链里插。
4.插值后剩余部分加入主链条尾部


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
     //思路：以l1作为主链，拿l2往里插
      if (l1==null||l2==null){
            return l1==null?  l2: l1;
        }
        if (l1.val>l2.val){
            ListNode temp = l1 ;
            l1 = l2 ;
            l2 = temp ;
        }
        ListNode head = l1 ;
        while (l1.next!=null&&l2!=null){
         if (l1.next.val>=l2.val){
             ListNode element = l2;
             l2 = l2.next;
             element.next = l1.next;
            l1.next = element;
            l1 = l1.next;
         }else {
             l1 = l1.next ;
         }
        }
        l1.next =  l2 == null ? l1.next : l2;
        return  head;
}
}
```