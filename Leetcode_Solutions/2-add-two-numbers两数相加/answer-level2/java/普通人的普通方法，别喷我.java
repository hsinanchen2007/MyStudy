### 解题思路
思路如代码注释

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
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		
		// 前置判断
		if(l1 == null && l2 != null){
			return l2;
		}else if(l1 != null && l2 == null){
			return l1;
		}else if(l1 == null && l2 == null){
			return null;
		}
		
		// 进位标志
		boolean flag = false;
		// 头索引
		ListNode head = new ListNode(0);
		ListNode index;
		index = head;

		// 两个链表一起走的情况
		while(l1!=null && l2!=null){
			// 先计算两个节点的值
			int tmpVal = l1.val+l2.val;
			// 先判断是否需要进位
			if(flag){
				// 进位的情况下
				// l1和l2的值相加大于等于10 或者加上进位后大于等于10都需要再进位
				if(tmpVal>=10 || tmpVal+1>=10){
					tmpVal = tmpVal - 10 + 1;
				}else{
					// 要不然就只加上上次进位的结果，将进位标志置位false
					tmpVal+=1;
					flag = false;
				}
			}else{
				// 如果上次没有进位值的情况下
				// 判断l1+l2的值是否大于等于10
				// 1、若大于则减去10，置进位标志为true
				// 2、置进位标志为false
				if(tmpVal>=10){
					tmpVal -= 10;
					flag = true;
				}else{
					flag = false;
				}
			}
			// 给index后面追加节点
			index.next = new ListNode(tmpVal);
			// index 和 l1、l2指针移动
			index = index.next;
			l1 = l1.next;
			l2 = l2.next;
		}
		
		// 若l2为空时候l1不为空，那么继续遍历l1
		while(l1 != null){
			// 若到达这里时候还有进位
			if(flag){
				// 若l1节点值+进位大于等于10，将值加进位减去10的节点追加在结果链表，继续保持进位标志为true
				if(l1.val+1>=10){
					index.next = new ListNode((l1.val+1)-10);
				}else{
					// l1的值+进位小于10，则直接追加l1+进位值到链表尾部，并置进位标识符为false
					index.next = new ListNode((l1.val+1));
					flag = false;
				}
			}else{
				// 若无进位标志，则直接将l1后面值都添加到结果链表中
				index.next = new ListNode(l1.val);
			}
			// 指针移动
			index = index.next;
			l1 = l1.next;
		}
		// 若l2不为空，则将l2按照上面类似逻辑追加到结果链表
		while(l2 != null){
			if(flag){
				if(l2.val+1>=10){
					index.next = new ListNode((l2.val+1)-10);
				}else{
					index.next = new ListNode((l2.val+1));
					flag = false;
				}
			}else{
				index.next = new ListNode(l2.val);
			}
			index = index.next;
			l2 = l2.next;
		}
		// 这个是节点为 l1:9,l2:1的情况下做的后续处理
		if(flag){
			index.next = new ListNode(1);
		}
		
		// 最后返回结果
		return head.next;
    }
}
```