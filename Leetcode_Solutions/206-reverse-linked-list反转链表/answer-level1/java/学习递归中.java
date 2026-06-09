### 解题思路
@mata川 大神指导 递归三步骤。
1，找出终止条件   head == null  找出最后一个元素
2，找出返回结果   最后一个元素，开始的列表
3。找出循环过程   reverse(head.next);

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
        if(head==null){
            return head;
        }
        return reverse(head).next;//去假除头
    }
    public ListNode  reverse(ListNode head){
        if(head == null){//递归结束条件
            return new ListNode(-1);
        }
        ListNode newHeadnode =  reverse(head.next);//返回-1 开始新头
        ListNode flag = newHeadnode;
        while(flag.next!=null){
            flag=flag.next;//将指针移动到最后进行添加
        }
        flag.next = new ListNode(head.val);
        return newHeadnode;//返回新头开始的序列
    }
}
```