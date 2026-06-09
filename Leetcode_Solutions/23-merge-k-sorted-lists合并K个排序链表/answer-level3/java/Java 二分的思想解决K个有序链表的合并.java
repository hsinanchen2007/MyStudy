### 解题思路
解题思路: 
1. 核心还是两个有序链表的合并
2. 可以架一个循环，两两合并（前面两个合并的结果后下一个链表继续合并），这样需要处理n-1次两两合并
3. 另一种思路二分法，逐渐分割为最小粒度即两个有序链表合并，然后返回上一层继续进行合并，这样可以减少合并的次数（即下面代码的实现）

### 代码

```java
class Solution {
	public ListNode mergeKLists(ListNode[] lists) {
		if(lists==null || lists.length==0) {
			return null;
		}
		return helper(lists, 0, lists.length-1);
	}
	
	//通过mid将数组一分为二，并不断缩小规模，当规模为1时返回并开始合并
	//通过合并两个链表，不断增大其规模，整体看就是不断缩小-最后不断扩大的过程
	private ListNode helper(ListNode[] lists, int begin, int end) {
		if(begin == end) {
			return lists[begin];
		}

		int mid = begin + (end - begin) / 2;
		ListNode left = helper(lists, begin, mid);
		ListNode right = helper(lists, mid + 1, end);
		return mergeTwoLists(left, right);
	}
	
	//合并两个有序链表
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return null;
        }
        if (l1 == null || l2 == null) {
            return l1 == null ? l2 : l1;
        }
        
        ListNode newHead = new ListNode(0);
        ListNode p = newHead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                p = p.next = l1;
                l1 = l1.next;
            } else {
                p = p.next = l2;
                l2 = l2.next;
            }
        }
        
        if (l1 != null) {
            p.next = l1;
        } else {
            p.next = l2;
        }
        return newHead.next;
    }   
}
```