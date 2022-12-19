### 解题思路
1. 定义两个指针都指向head;
2. 第一个指针先移动k-1次，第二个指针不动；
3. 两个指针在相距k-1的情况下同时向右移动，直到第一个指针.next==null；
4. 输出第二个指针指向的节点；

##### 注意三点：
- 考虑head==null的情况；
- 考虑k==0的情况
- 考虑k>链表长度的情况；
![删除倒数第k个链表.gif](https://pic.leetcode-cn.com/973b150b84b6a6ce9038c8f7edc26ae47fcc659e2e98d0415c39a66ddadc5a1f-%E5%88%A0%E9%99%A4%E5%80%92%E6%95%B0%E7%AC%ACk%E4%B8%AA%E9%93%BE%E8%A1%A8.gif)

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head==null || k==0) {
			return null;
		}
		ListNode prev,curr;
		prev=head;
		curr=head;
		
		int i=0;
		while(i<k-1 ) {
			curr=curr.next;
			i++;
            if(curr==null) {
				return null;
			}
		}
		while(curr.next!=null) {
			curr=curr.next;
			prev=prev.next;
		}
		return prev;
    }
}
```