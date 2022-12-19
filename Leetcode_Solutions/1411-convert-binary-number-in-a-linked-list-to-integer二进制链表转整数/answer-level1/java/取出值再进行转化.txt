首先，创建一个 list对象 用于保存从 ListNode head 中获得的值。
此后利用Java的 Integer.valueOf(String s,int radix) 方法将**二进制转化为十进制**即可。


```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        List<Integer> list = new ArrayList<>();
        while(head != null){
            list.add(head.val);
            head = head.next;
        }
        return Integer.valueOf(list.toString().replace(",","").replace("[","").replace("]","").replace(" ",""),2);
    }
}
```
