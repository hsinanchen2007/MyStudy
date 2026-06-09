### 解题思路

- 本人先用**单指针**实现了节点的删除，思路简单，但是耗时长（2ms），是**双指针**的两倍，而且涉及到`temp.next.next`等语句，稍有不慎则报错。

- 基于上述缺点，笔者后来参考了双指针的做法：定义**prev和curr**分别指向哨兵节点和head节点，逐步遍历，直到删除所有的含有val数值的节点。
- 需要指出，题目中的Head节点和我们之前考虑的不太一样，它并不是哨兵节点，而是存放具体数据的。

### 代码
```java []
class Solution {
// 双指针
    public ListNode removeElements(ListNode head, int val) {
        ListNode parent = new ListNode(-1);
		parent.next=head;
		
		ListNode prev=parent,curr=head;
		while(curr!=null) {
			if(curr.val==val) {
				prev.next=curr.next;
			}else {
				prev=prev.next;
			}
			curr=curr.next;
		}
		return parent.next;
    }
}
```
```java []
class Solution {
// 单指针
    public ListNode removeElements(ListNode head, int val) {
        ListNode parent = new ListNode(-1);
		parent.next=head;
//		设计哨兵节点,并让他们与head节点构建关系
		ListNode temp=parent;
		while(temp!=null ) {
			if( temp.next!=null&&temp.next.val==val) {
				temp.next=temp.next.next;
			}else{
				temp=temp.next;
			}
		}
		return parent.next;
    }
}
```
