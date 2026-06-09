执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 : 37 MB , 在所有 Java 提交中击败了 5.02% 的用户

思路：
遍历链表记录m，n所在的节点和m的前一个节点、n的后一个节点
然后将m到n之间的节点进行反转
之后再将其连接到m的前一个节点上和n的后一个节点上
注意：m有可能是第一个节点所有要做一个判断，n也有可能是最后一个节点，不影响程序执行。

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
    public ListNode reverseBetween(ListNode head, int m, int n) {

        ListNode mNode = null;
    	ListNode nNode = null;
    	ListNode mPrev = null;
    	ListNode nNext = null;
    	
    	int i = 0;
    	ListNode curr = head;
    	while(curr != null) {
    		i ++;
    		if(i == m - 1) {
    			mPrev = curr;
    		} else if(i == m) {
    			mNode = curr;
    		} else if(i == n) {
    			nNode = curr;
    		} else if(i == n + 1) {
    			nNext = curr;
    		}
    		curr = curr.next;
    		
    	}
    	
    	ListNode prev = nNext;
    	ListNode currTemp = mNode;
    	int j = m;
    	while(j <= n) {
    		ListNode nextTemp = currTemp.next;
    		currTemp.next = prev;
    		prev = currTemp;
    		currTemp =nextTemp;
    		j ++;
    	}
    	
    	if(mPrev != null) {
    		mPrev.next = prev;
    	} else {
    		head = prev;
    	}
    	
    	return head;
    }
}
```
