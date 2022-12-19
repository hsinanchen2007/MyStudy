### 解题思路
不改变链表结构的前提下，利用栈存放链表从前到后的顺序

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
   public int[] reversePrint(ListNode head) {
        Stack<Integer> s = new Stack<>();
        ListNode p =head;
        int length = 0;
        while (p!=null){
            s.push(p.val);
            p=p.next;
            length++;
        }

        int[] arr =new int[length];
        length=0;
        while (!s.isEmpty()){
            arr[length++]=s.pop();
        }
        return arr;
    }
}
```