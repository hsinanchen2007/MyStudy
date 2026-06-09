### 解题思路
此处撰写解题思路

时间复杂度为O(N),空间复杂度为O(1);
思路清晰!先计算出链表的长度，然后把前一段反转(注意反转后的头结点)，和后一段依次比较，若值不相等直接返回false;若都相等就返回true;

俺也是萌新，刚开始的时候想着把整个链表反转然后和旧的依次比较，但是发现旧的不能直接保存，比如用oldHead保存head,反转之后发现oldHead会指向链表反转后尾部的结点，并没有生成新的链表储存head。虽然看到别人的思路是取中点，逆转前半部分然后依次比较，但还是纠结自己的方法为啥不行，想了好久才知道；

或者可以重新定义N个List依次把head里的元素copy下来，在反转和原来的head比较；只是空间复杂度为O(N)了时间复杂度没变；
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
    public boolean isPalindrome(ListNode head) {
        int len = 0;ListNode pt = head;
        ListNode p1 = head; ListNode p2 = null;
        while(pt!=null){
            len++;
            pt = pt.next;
        }
        int k = len/2;
        if(len==0||len==1) return true;
        else{
            pt = head;
            for(int i = 1; i < k; i++){
                pt = pt.next;
            }
            if(len%2==0){
                p2 = pt.next;
            }else{
                p2 = pt.next.next;
            }
            pt.next = null;
        }
        ListNode pre = null, cur = head, tmp = null;
        while(cur!=null){
            tmp = cur.next;
            cur.next =pre;
            pre = cur;
            cur = tmp;
        }
        p1 = pre;
        while(p1!=null){
            if(p1.val != p2.val) return false;
            p1 = p1.next;
            p2 = p2.next;
        }
        return true;
        
    }
}
```