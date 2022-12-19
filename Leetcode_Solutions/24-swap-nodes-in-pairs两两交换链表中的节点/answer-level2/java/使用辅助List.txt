### 解题思路
将Node添加至List
List转数组,交换位置
修改next指针

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
    public ListNode swapPairs(ListNode head) {
    	if(head==null) {
    		return head;
    	}
    	List<ListNode> result = new LinkedList<>();
    	ListNode curr = head;
    	while(curr!=null) {
    		result.add(curr);
    		curr=curr.next;
    	}
    	ListNode [] arr = result.toArray(new ListNode[result.size()]);
    	for(int i=0;(i+1) < arr.length && i<arr.length;i+=2) {
    		ListNode temp = arr[i];
    		arr[i] = arr[i+1];
    		arr[i+1] = temp;
            if((i+1)==arr.length-1) {
    			arr[i+1].next=null;
    		}
    	}
    	for(int i=0;(i+1)<arr.length&&i<arr.length;i++) {
    		arr[i].next=arr[i+1];
    	}
    	return arr[0];
    }
}
```