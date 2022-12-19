### 解题思路
都这么喜欢效率和内存？全程不申请新节点空间`：将两条链表同时顺序访问结果相加不进位填入数组内(不用List也是为了节省时间，也许可以不申请那么大的空间)，最后生成链表的时候再处理进位，数组数据damp进链表的时候不进行申请Node结点空间，使用较长的那条链作为母链依附修改，在最高位需要进1的时候使用短链的首节点的内存，显然运行完后原来的链表l1和l2都被破坏了，全程的变量申请只少不多，变量用完一个阶段之后可能作为后续的其他阶段的其他变量使用，但是用java还追求什么效率？毫无可读性和安全性，工作使用三天就被开除

作者：ren-xuan
链接：https://leetcode-cn.com/problems/add-two-numbers/solution/javade-2msbu-shen-qing-nodejie-dian-de-bao-li-jie-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
 public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		if (l1.val == 0 && l1.next == null)
			return l2;
		else if (l2.val == 0 && l2.next == null)
			return l1;
		int more =0;
		int index=0;
		int []arr=new int[127];
		ListNode cur2, cur1;
		cur1 = l1;
		cur2 = l2;
		int lenth1 = 0, lenth2 = 0;
		while (!(cur1 == null && cur2 == null)) {
			if (cur1 != null) {
				if (cur2 != null) {
					arr[index]=cur1.val + cur2.val;
					index++;
					cur1 = cur1.next;
					cur2 = cur2.next;
					lenth1++;
					lenth2++;
				} else if (cur2 == null) {
					arr[index]=cur1.val;
					index++;
					cur1 = cur1.next;
					lenth1++;
				}
			}
			if (cur1 == null) {
				if (cur2 != null) {
					arr[index]=cur2.val;
					index++;
					cur2 = cur2.next;
					lenth2++;
				}
			}
		}
		if (lenth1 > lenth2) {
			cur1 = l1;
			lenth2 = 0;
			while (cur1.next!= null) {
				more=(arr[lenth2]+more);
				if(more>=10) {
					cur1.val = more%10;
					more=1;
				}else {
					cur1.val = more;
					more=0;
				}
				lenth2++;
				cur1 = cur1.next;
			}

			//替代cur2！=null的额外操作
			more=(arr[lenth2]+more);
			if(more>=10) {
				cur1.val = more%10;
				more=1;
			}else {
				cur1.val = more;
				more=0;
			}
			lenth2++;
			//替代cur2！=null的额外操作
			if(more==0)return l1;
			cur1.next = l2;
			cur1.next.val=1;
			cur1.next.next=null;
			return l1;
		} else {
			cur2 = l2;
			lenth1 = 0;
			while (cur2.next!= null) {
				more=(arr[lenth1]+more);
				if(more>=10) {
					cur2.val = more%10;
					more=1;
				}else {
					cur2.val = more;
					more=0;
				}
				lenth1++;
				cur2 = cur2.next;
			}
		
			//替代cur2！=null的额外操作
			more=(arr[lenth1]+more);
			if(more>=10) {
				cur2.val = more%10;
				more=1;
			}else {
				cur2.val = more;
				more=0;
			}
			lenth1++;
			//替代cur2！=null的额外操作
			if(more==0)return l2;
			cur2.next = l1;
			cur2.next.val=1;
			cur2.next.next=null;
			return l2;
		}

	}

    
}

