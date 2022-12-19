![截图.png](https://pic.leetcode-cn.com/e8b4da64da195721d083b816b6bd20802c0fd9f0e20f1562ce7f51d52b01d3f4-%E6%88%AA%E5%9B%BE.png)

```c++
class Solution {
public:
	
	Node* copyRandomList(Node* head) {
		if (head == NULL)
		{
			return head;
		}
		map<Node*, Node*> listOldAndNew;
		Node* newHead = new Node(head->val);
		Node* iterNew = newHead;
		Node* iterSrc = head;
		listOldAndNew[iterSrc] = iterNew;
		while (iterSrc->next != NULL)
		{
			iterNew->next = new Node(iterSrc->next->val);
			iterSrc = iterSrc->next;
			iterNew = iterNew->next;
			listOldAndNew[iterSrc] = iterNew;
		}

		iterNew = newHead;
		iterSrc = head;
		while (iterSrc != NULL)
		{
			iterNew->random = listOldAndNew[iterSrc->random];
			iterSrc = iterSrc->next;
			iterNew = iterNew->next;
		}

		return newHead;
	}

};
```
先进行常规的链表copy，在copy过程中用map记住新旧链表的节点映射。然后在重新遍历一遍列表，把新链表中的`random`信息填写上