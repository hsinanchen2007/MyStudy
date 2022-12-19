### 解题思路
方法1：迭代
设置三指针，cur指向head，pre为head的上一个节点（null），一个临时借用tmp用以交换。
利用while循环遍历链表，tmp先存储cur的next节点，cur的next节点指向pre，然后pre和cur分别往后移动一位。重复此操作直至cur为空（即遍历完毕）。画图有助于理解。

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
    public ListNode reverseList(ListNode head) {
        ListNode pre = null,tmp = null;
        ListNode cur = head;
        while(cur != null){
            tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        
        }
        return pre;
    
    }
}
```

方法2：递归
先通过递归调用，最后一层递归能得到最后一个节点，作为新的头节点。
最后一层递归完后，会反向遍历，执行接下来的局部反转指针语句【当前节点的next节点的next指针指向自己，实现了当前节点的原本下一个节点的next指针变成了自己，成功反转，再令当前节点的next指针为空，让其重复此操作】。

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
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;

        ListNode node = reverseList(head.next);//得到新的头节点
        //反转指针
        head.next.next = head;
        head.next = null;

        return node;
    
    }
}
```