### 解题思路
此处撰写解题思路
如果只用一次遍历就解决问题，那我选择用map来保存每一个节点对应的下标，这样每次只要拿到要删除节点的下标，
就可以将它的前后节点进行衔接
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        Map<Integer,ListNode>map=new TreeMap<>();
        int count=0;
        while (head!=null){
            map.put(count++,head);
            head=head.next;
        }
        int deleteIndex=count-n;
        if(deleteIndex==0){
            return map.get(deleteIndex+1);
        }else if(deleteIndex==count-1){
            map.get(deleteIndex-1).next=null;
            return map.get(0);
        }else{
            map.get(deleteIndex-1).next=map.get(deleteIndex+1);
            return map.get(0);
        }
    }
}
```