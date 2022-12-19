### 解题思路
此处撰写解题思路
最开始的时候,看到这道题,就想先把两个逆序链表中的数先提取出来恢复成正常的两个非负整数,
然后相加,将相加的结果逆序存放在一个新的链表中返回,用的HashMap做的,然后感觉这样做代码
非常的繁杂,虽然时间复杂度不是那么高,但是效率很低,而且对HashMap的操作不熟练做了很久失败了.
看了官方解答的这个版本,感觉自己好蠢呀,人家就首先定义一个哑节点,然后根据l1,l2的当前节点的情况顺序
取值,设置一个进制位,用于对下一个节点是否加1判断.然后将当前循序下的l1,l2节点进行求和,取模操作,将取模后的sum赋值给当前节点,同时进行l1,l2,curr节点的下个结点的更新,一直循环到l1,l2的下一个节点都为空,最后对
进制位carry进行判断,是否将curr节点的下一个节点加1更新,返回新的节点.最后一点有点没看明白,为什么返回的是dummyHead.next而不是dummyHead
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
class Solution{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}
}
```