### 解题思路
此处撰写解题思路

![WechatIMG81.png](https://pic.leetcode-cn.com/7b37ef262d03a24a7ff38e35b49b9d41c7a57af5aa90f8563b1d2dc6f99d7b04-WechatIMG81.png)


此题和第21题类似，21题是合并两个链表，那么此题可采用递归的方法，逐渐的缩小合并数量。
例如，要合并16个链表，可以先合并1-2，3-4，5-6，7-8，9-10，11-12，13-14，15-16
这样问题就变成了合并8个链表，以此类推，将问题最后变成合并两个连链表

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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode result = new ListNode(-1);
		int length = lists.length;
		if(lists==null||length==0) {
			return result.next;
		}
		if(length==1) {
			return lists[0];
		}
		boolean isEven = length%2==0;
		int arrayLength = isEven?length/2:length/2+1;
		ListNode[] listNodes = new ListNode[arrayLength];
		for(int i=0;i<length/2;i++) {
			listNodes[i] = mergeTwoLists(lists[i*2],lists[i*2+1]);
		}
		if(!isEven) {	
			listNodes[length/2] = lists[length-1];
		}
		return mergeKLists(listNodes);
	}

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode result = new ListNode(-1);
		ListNode prev = result;
		while(l1!=null&&l2!=null) {
			if(l1.val<=l2.val) {
				prev.next = l1;
				l1 = l1.next;
			}else {
				prev.next = l2;
				l2 = l2.next;
			}
			prev = prev.next;
		}
		prev.next = l1==null?l2:l1;
		return result.next;
	}

}
```