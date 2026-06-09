### 解题思路
对k进行求余可以知道从实际第几位开始拼接

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
    public ListNode rotateRight(ListNode head, int k) {
        ArrayList<Integer> a = new ArrayList<>();
        if(head==null||head.next==null||k==0){return head;}
        ListNode temp = head;a.add(head.val);
        while(temp.next!=null){
            temp = temp.next;
            a.add(temp.val);
        }
        int start =(a.size()- (k%a.size()))==a.size()?0:a.size()- (k%a.size());
        ListNode ans = new ListNode(a.get(start));ListNode temp1 = ans;
        for(int i = 1;i<a.size();i++){
            temp1.next = new ListNode(a.get((start+i)%a.size()));temp1 = temp1.next;
        }
        return ans;
    }
}
```