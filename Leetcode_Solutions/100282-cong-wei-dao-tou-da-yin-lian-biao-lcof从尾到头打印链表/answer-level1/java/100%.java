### 解题思路
1.遍历一遍链表获得链表长度count
2.创建相应长度数组
3.再次遍历链表同时将节点的值传入数组，因为要求逆序，控制循环的剩余长度值正好相应的对应了数组的标识

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
        int count=0;
        ListNode curr=head;
        while(true){
            if(curr==null){
                break;
            }
            count++;
            curr=curr.next;
        }
        int arr[]=new int[count];
        ListNode curr1=head;
        for(int i=count-1;i>=0;i--){
            arr[i]=curr1.val;
            if(curr1.next!=null){
                curr1=curr1.next;
            }
        }
        return arr;
    }
}
```