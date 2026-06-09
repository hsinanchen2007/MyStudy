一、递归
99% 90% 递归做法 回溯相加
```java
class Solution{
//	public class ListNode{
//		int val;
//		ListNode next;
//		ListNode(int x){
//			val = x;
//		}
//	}
    public ListNode addTwoNumbers(ListNode l1, ListNode l2){
        //先规范l1、l2两个链表，使他们相同长度，不足长度的在高位补0
        int l1_length = getListLength(l1);
        int l2_length = getListLength(l2);
        if(l1_length > l2_length){
            int differ = l1_length - l2_length;
            l2 = repair(l2, differ);
        }else if(l1_length < l2_length) {
        	int differ = l2_length - l1_length;
        	l1 = repair(l1, differ);
        }
        //然后递归做法从低位相加（回溯相加）
        ListNode result = recursionAdd(l1, l2);
        //处理最后一位相加之后🈶进位的情况
        if(result.val == 0) {
        	return result.next;
        }else {
			return result;
		}
    }
    //根据需要补齐的位数，在头结点之前补上以0为值构造的结点
    public ListNode repair(ListNode l, int differ) {
        ListNode dummy = new ListNode(-1), temp = dummy;
        while(differ > 0) {
        	temp.next = new ListNode(0);
        	temp = temp.next;
        	differ --;
        }
        temp.next = l;
        return dummy.next;
    }
    //计算链表长度
    public int getListLength(ListNode l){
        int result = 0;
        ListNode temp = l;
        while(temp != null){
            result ++;
            temp = temp.next;
        }
        return result;
    }
    //递归做法实现回溯相加
    public ListNode recursionAdd(ListNode l1, ListNode l2) {
        //退出条件：两个链表都为空时
        if(l1 == null && l2 == null)  return new ListNode(0);

        int sum = l1.val + l2.val;
        ListNode next = recursionAdd(l1.next, l2.next);
        ListNode curr = null;
        //加上进位之后，又产生了进位
        if((next.val + sum % 10) >= 10) {
        	next.val = (next.val + sum % 10) % 10;
        	curr = new ListNode(sum / 10 + 1);
        }
        //加上低位产生的进位
        else {
        	next.val += sum % 10;
        	curr = new ListNode(sum / 10);
        }
        curr.next = next;
        return curr;
    }
}
```

二、正常思路
先反转两个链表，再相加，加完之后再把新链表反转
```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	return reverse(add(reverse(l1), reverse(l2)));
    }
    public ListNode add(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode p = l1, q = l2, cur = result;
        int carry = 0;
        while(p != null || q != null){
            int a = (p != null) ? p.val : 0;
            int b = (q != null) ? q.val : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            cur.next = new ListNode(sum % 10);
            cur = cur.next;
            if(p != null) p = p.next;
            if(q != null) q = q.next;  
        }
        if(carry > 0)   cur.next = new ListNode(carry);
        return result.next;
    }
    public ListNode reverse(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode pre = null, curr = head, next = null;
        pre = curr;
        curr = curr.next;
        next = curr.next;
        while(true){
            curr.next = pre;
            if(next == null) break;
            pre = curr;
            curr = next;
            next = next.next;
        }
        head.next = null; 
        return curr;
    }
}
```