# 解题思路：
&emsp;&emsp;找到中间节点，将中间节点后面的部分进行反转，从头节点与尾节点开始遍历比较，如果对称位置上的值不相等则直接返回false。
## 寻找中间节点
&emsp;&emsp;起始时p1、p2处于头节点，p1每移动一个节点，p2需要移动两个，保证最后p1处于链表的中间位置
![微信图片_20200215213225.jpg](https://pic.leetcode-cn.com/1ca73fbebf47d5826f75423a088ee970e6ef2a86309154ac26230bb1bf89ba5a-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200215213225.jpg)

```java []
ListNode p1 = head;
ListNode p2 = head;
while(p2.next!=null && p2.next.next!=null){
    p1 = p1.next;
    p2 = p2.next.next;
}
```
## 翻转中间节点后面的链表
&emsp;&emsp;设置curr初始值为null，curr始终代表翻转链表的头节点。
```java []
//反转中间节点后面的链表
p1 = p1.next;
ListNode temp = null;
ListNode curr = null;
while(p1 != null){
    //保存p1的下一节点地址
    temp = p1.next;
    //p1的下一个节点为反转链表的头节点
    p1.next = curr;
    //更新反转链表的头节点
    curr = p1;
    //p1指针指向下一节点
    p1 = temp;
}
```
&emsp;&emsp;翻转链表的递归写法，调用的时候传入中间节点的下一个节点p1.next
```java []
public ListNode reverse(ListNode head){
    if(head.next == null){
        return head;
    }
    //保持p不变，将p返回
    ListNode p = reverse(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
```
## 最后同时从head、curr开始遍历比较
下面为解法代码：
```java []
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
        ListNode p1 = head;
        ListNode p2 = head;
        ListNode temp = null;
        ListNode curr = null;
        if(head==null || head.next == null)
            return true;
        while(p2.next!=null && p2.next.next!=null){
            p1 = p1.next;
            p2 = p2.next.next;
        }
        //反转中间节点后面的链表
        p1 = p1.next;
        while(p1 != null){
            //保存p1的下一节点地址
            temp = p1.next;
            //p1的下一个节点为反转链表的头节点
            p1.next = curr;
            //更新反转链表的头节点
            curr = p1;
            //p1指针指向下一节点
            p1 = temp;
        }
        while(curr!=null){
            if(head.val == curr.val){
                head = head.next;
                curr = curr.next;
            }else{
                return false;
            }
        }
        return true;
    }
    
}
```
翻转链表采用递归时写法：
```java []
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
        ListNode p1 = head;
        ListNode p2 = head;
        ListNode temp = null;
        ListNode curr = null;
        if(head==null || head.next == null)
            return true;
        while(p2.next!=null && p2.next.next!=null){
            p1 = p1.next;
            p2 = p2.next.next;
        }
        //反转中间节点后面的链表
        curr = reverse(p1.next);
        while(curr!=null){
            if(head.val == curr.val){
                head = head.next;
                curr = curr.next;
            }else{
                return false;
            }
        }
        return true;
    }
    public ListNode reverse(ListNode head){
        if(head.next == null){
            return head;
        }
        //p在递归中始终指向翻转链表的头节点，保持p不变，将p返回
        ListNode p = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return p;
    }
    
}
```
