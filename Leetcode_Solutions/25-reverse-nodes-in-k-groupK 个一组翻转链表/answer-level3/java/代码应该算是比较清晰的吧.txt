构造一个存储结点的栈，然后采用递归方法就可以了。
旁友指正空间复杂度不符合要求...当时没看到，大家看一下就好了。
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.14%
的用户
```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
		int i = k;
		ListNode[] stack = new ListNode[k];//没有无参构造方法，但是构建了没有值的结点。相当于int i;
		ListNode q = head;
		while(k>0) {//把当前k个结点存入栈中。
			stack[i-k] = q;
			if (q!=null) q=q.next;
			else return head;//结点凑不到k个时，直接返回原部分链表。
			k--;
		}
		while(k<i-1) {
			k++;
			stack[i-k].next=stack[i-k-1];
		}
		stack[0].next=reverseKGroup(q, k+1);
		return stack[i-1];
    }
}
```
