### 执行结果
用时2ms,击败了68.87%的用户
内存消耗43.5MB,击败了100%的用户
### 解题思路
考虑到是从尾到头打印元素，符合先入后出的原则，于是想到了栈；
1. 从头到尾将链表中的值压入堆栈；
2. 将栈中数据压出，放置在数组中
![image.png](https://pic.leetcode-cn.com/e27edcaa8bd942997c36dede1e438f815c734c6e0722ab847f78212c8ba10f0a-image.png)

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
        Stack<Integer> st= new Stack<Integer>();
		ListNode temp=head;
		while(temp!=null) {
			st.push(temp.val);
			temp=temp.next;
		}
		int [] arr=new int[st.size()];
		int i=0;
		while(!st.isEmpty()) {
			arr[i]=st.pop();
			i++;
		}
		return arr;
    }
}
```