时间复杂度 = O( 2n ), 空间复杂度 = O( treeHeight )。


```java
class Solution {
	private Node head;
	private Node tail;

	public Node treeToDoublyList( Node root ) {
		Node p1 = null, p2 = null, p3 = null;

		if( root == null ) {
			return root;
		}
		recursion( root ); // 中序遍历得到只有后继的单向链表.
		for( p1 = null, p2 = head; p2 != null; p2 = p2.right ) { // 双指针逆序法,更新每个结点的前驱.
			p2.left = p1;
			p1 = p2;
		}
		head.left = tail;  // 头指向尾.
		tail.right = head; // 尾指向头.

		return head;
	}

	private void recursion( Node root ) {
		Node node = null;

		if( root == null ) {
			return;
		}
		recursion( root.left );
		node = new Node( root.val );
		head = head != null ? head : node;
		if( tail != null ) {
			tail.right = node;
		}
		tail = node;
		recursion( root.right );
	}
}
```
