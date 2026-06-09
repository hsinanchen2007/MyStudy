### 解题思路
1、先求链表长度，确定循环次数（即共有多少个交换组）。
2、根据k值确定每个交换组的交换次数。
3、设立dummy和cur作为一个交换组的固定指针，设立temp指针为浮动指针。
4、利用temp指针进行遍历，完成交换。

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null) return null;
        int len = listNodeLength(head);
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode ans = dummy;
        ListNode cur = dummy.next;
        for(int i=0;i<len/k;i++){
            for(int j=1;j<k;j++){
                ListNode temp = cur.next;
                cur.next = temp.next;
                temp.next = dummy.next;
                dummy.next = temp;
            }
            dummy = cur;
            cur = cur.next;
        }
        return ans.next;
    }
    public int listNodeLength(ListNode head){
        int count = 0;
        while(head!=null){
            count+=1;
            head=head.next;
        }
        return count;
    }
}
```