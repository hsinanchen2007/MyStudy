### 解题思路
1. 从个位加起，刚好是逆序，从链表头结点开始，两个链表保持步长为1，依次相加，做好进位记录
2. 把结果集存放在其中一个链表上（l1）, 如果l1比l2长，剩余的部分处理好进位，直到没有进位时结束
3. 如果l2比l1长，把l1的尾结点的指针指向l2的后半部分，然后处理逻辑同步骤2
4. 最后注意一点 最后一个节点可能有进位，需要新增一个节点。

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
        ListNode result = l1;
        int up = 0;//进位
        while(l1.next != null && l2.next !=null){
            l1.val= l1.val + l2.val + up;
            up= l1.val /10;
            l1.val %= 10;

            l1 = l1.next;
            l2 = l2.next;
        }

        l1.val= l1.val + l2.val + up;
        up= l1.val /10;
        l1.val %= 10;

        if(l2.next!=null){
            l1.next = l2.next;
        }
       
            while(l1.next!=null){
                l1 = l1.next;
                l1.val= l1.val  +up;
                up= l1.val /10;
                if(up == 1){
                    l1.val -=10; 
                }else if(up ==0){
                    break;
                }
            }
            if(up == 1){
                l1.next = new ListNode(1);
            }
            return result;
        
    }
}
```