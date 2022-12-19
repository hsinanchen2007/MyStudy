### 解题思路
1.遍历链表获得长度
2.再次遍历链表，数组从尾到头插入数据
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
        //1.得到数组长度
        //2.从后往前填装数组
        int size=0;
        ListNode cur=head;
        while(cur!=null){
            size++;
            cur=cur.next;
        }
        int [] result=new int [size];
        cur=head;
        for(int i=size-1;i>=0;i--){
            result[i]=cur.val;
            cur=cur.next;
        }
        return result;
    }
}
```