### 解题思路
不采用额外存储空间的话，其实就是递归了。（不过递归不也使用了更多的堆栈空间吗，不太理解）。
首先生成新的链表，其中链表的每个节点都是l1和l2对应节点值的和。
然后进行递归，思路就是先判断前一个节点值是否大于等于10，以此决定是否有进位。

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //1.计算一下l1和l2的长度
        int len1 = 0, len2 = 0;
        ListNode l = l1;
        while(l != null){
            len1++;
            l = l.next;
        }
        l = l2;
        while(l != null){
            len2++;
            l = l.next;
        }
        //2.对两个l进行调整，长的的为l1
        if(len1 < len2){
            int temp = len1;
            len1 = len2;
            len2 = temp;
            ListNode tempNode = l1;
            l1 = l2;
            l2 = tempNode;
        }
        //3.新建一个链表，存储l1和l2逐位累加结果
        ListNode re = new ListNode(0);
        ListNode head = re;
        //  先加l1长出来的部分
        while(len1 > len2){
            re.next = new ListNode(0);
            re = re.next;
            re.val = l1.val;
            l1 = l1.next;
            len1--;
        }
        //  再加l1和l2共有部分
        while(len1 > 0){
            re.next = new ListNode(0);
            re = re.next;
            re.val = l1.val + l2.val;
            l1 = l1.next;
            l2 = l2.next;
            len1--;
        }
        //4.对新链表用add函数递归进行调整，主要是进位问题
        int last = add(head.next);
        //  如果最高位仍有进位，用head保存；无进位则返回head.next
        if(last == 1){
            head.val = 1;
            return head;
        }else{
            return head.next;
        }
    }

    public int add(ListNode l){
        if(l == null){
            return 0;
        }
        int last = add(l.next);
        l.val += last;
        if(l.val >=10){
            l.val -= 10;
            return 1;
        }else{
            return 0;
        }
    }
}
```