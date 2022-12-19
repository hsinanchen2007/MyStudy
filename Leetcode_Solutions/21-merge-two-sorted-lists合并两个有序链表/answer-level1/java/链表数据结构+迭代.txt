1、单链表的基本结构

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
```


用题目的定义类来看，链表是由头节点和指针组成的基本数据单元，代码块中val是链表的头节点，next是指针。

头节点插入数据的方法是ListNode(int x),  而指针指向的下一个节点又是一个链表单元，由此实现了可变长的数据结构。

增、删、改，对链表来说都很灵活，只要修改指针指向。而查找是缺点，要查找一个数必须从第一个链表节点顺序查起。

![1583676323628.png](https://pic.leetcode-cn.com/6ee754d191a28bc6b629a86a103141840e17335a6d058b5bb2ae69c4a2b70427-1583676323628.png)




2、回到题目

如果完全不懂链表的数据结构特点，可以把两个链表的元素提出组成一个数组，然后数据排序后再存为链表。

利用链表的结构特点，可以使用迭代算法，就把数组排序和新建链表合在一起。直接比较两个链表的第一个节点的数据大小，然后依序追加到新的链表上。

代码：
```
public class solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode mergeL= new ListNode(-1); // create a head-ListNode to point to merged result-ListNode
        
		ListNode merge=mergeL; // head-ListNode point to the start of result part
        
		while(l1!=null &&l2!=null){ // compare every val of two listnode until one become null
            
			if (l1.val<=l2.val){
				merge.next=l1;
				l1=l1.next;
			}else{
				merge.next=l2;
				l2=l2.next;
			}
           
			merge=merge.next;
		}
        
		merge.next=l1==null?l2:l1; // merge the other listnode while one is null
        
		return mergeL.next; // return the result-listnode
	}
}
```
