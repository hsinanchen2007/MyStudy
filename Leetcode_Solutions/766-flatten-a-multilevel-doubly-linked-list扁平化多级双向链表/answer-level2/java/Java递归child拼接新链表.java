**请结合以下代码注释图解食用。**
- 遍历到3的时候，存在child，将7作为3的next，得[1,2,3,7]
- 递归遍历7开头的链表，pre记录4的位置
- 遍历到8的时候，将11作为8的next,得[1,2,3,7,8,11]
- 递归遍历11开头的链表，pre记录9的位置

- 当遍历到12，next为NULL，此时[1,2,3,7,8,11,12]
- 结束递归，12后面继续拼接9及之后的链表，直到NULL，得[1,2,3,7,8,11,12,9,10]
- 结束递归，10后面继续拼接4及之后的链表，直到NULL，得[1,2,3,7,8,11,12,9,10,4,5,6]，得到结果
```
/*
* 1---2---3---4---5---6--NULL 
*         | 
*         7---8---9---10--NULL 
*             | 
*             11--12--NULL
*/

Node dummyHead = new Node();//虚拟头节点
Node ret = dummyHead;

public Node flatten(Node head) {
	if (head == null) {
		return null;
	}
	flatten(head, null);
	// 头节点的prev需要置空，否则会提示结果非双向链表
	ret.next.prev = null;
	return ret.next;
}

private void flatten(Node curr, Node preNext) {
	addNode(curr.val);//将child节点及其之前的所有节点按从头到尾顺序拼接到结果链表ret的尾部
	if (curr.child != null) {
		// 若当前节点有child节点，递归遍历子链表，
		//并记录当前链表的next为pre，在回溯时拼接到子链表的尾部
		Node pre = curr.next;
		curr.next = curr.child;
		flatten(curr.child, pre);
	} else if (curr.next != null) {
		//不存在child子链表，且还有next节点，则继续遍历向后遍历next
		//因为不存在child，pre置空即可
		flatten(curr.next, null);
	}
	//child子链表遍历结束后，将父链表后面的节点拼接到子链表的尾部
	while (preNext != null) {
		addNode(preNext.val);
		preNext = preNext.next;
	}
}

// 将新节点添加到结果链表ret的尾部
public void addNode(int val) {
	Node n = new Node();
	n.prev = dummyHead;
	n.val = val;
	dummyHead.next = n;
	dummyHead = n;
}
```
