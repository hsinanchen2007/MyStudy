### 解题思路
此处撰写解题思路

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
    public ListNode middleNode(ListNode head) {
        ListNode res=new ListNode(head.val);
        res.next=head.next;
        int length=0;
        while(res!=null){
            length++;
            res=res.next;
        }
        res=head;
        int num=0;
        if(length%2==0){
            num=length/2;
        }else{
            num=(length+1)/2-1;
        }
        
        for(int i=0;i<num;i++){
            res=res.next;
        }
        return res;
    }
}
```