### 解题思路
1.创建指针保存头节点
2.第一遍循环得到数组长度
3.第二遍逆向存储节点内的信息

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
        int count = 0;
        ListNode temp = head;
        while(temp != null){
            temp = temp.next;
            count++;
        }
        int[] res = new int[count];
        while(head != null){
            res[count-1] = head.val;
            count--;
            head = head.next;
        }
        return res;




        
    }
}
```