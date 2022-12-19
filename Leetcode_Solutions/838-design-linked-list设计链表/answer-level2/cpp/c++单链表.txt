### 解题思路
实现单链表需要注意的问题：1、为了方便处理链表边界问题，设置链表的头结点，需要注意头结点没有值，只有一个空域指针，指向链表的第一个节点；2、所有的插入和删除节点都是从第一个节点开始算的，不是头结点。

### 代码

```cpp
struct myListNode
{
	int val;
	myListNode* next;
	myListNode() :val(-1), next(nullptr) {}
};


class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList() :m_size(0)
	{
		m_head = new myListNode();
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index)
	{
		if (index > m_size - 1 || index < 0)
		{
			return -1;
		}
		myListNode* p = m_head->next;
		while (index != 0)
		{
			p = p->next;
			--index;
		}
		//std::cout << p->val;
		return p->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val)
	{
		myListNode* newNode = new myListNode();
		newNode->next = m_head->next;
		m_head->next = newNode;
		newNode->val = val;
		m_size += 1;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val)
	{
		myListNode* lastNode = new myListNode();
		lastNode->val = val;
		myListNode* p = m_head;
		int len = m_size;
		while (len != 0)
		{
			p = p->next;
			--len;
		}
		p->next = lastNode;
		lastNode->next = NULL;
		m_size += 1;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val)
	{
		if (index > m_size) return;
		if (index == m_size)
		{
			addAtTail(val);
			return;
		}
		if (index < 0)
		{
			addAtHead(val);
			return;
		}
		myListNode* newNode = new myListNode();
		myListNode* p = m_head;
		while (index != 0)
		{
			p = p->next;
			--index;
		}
		newNode->next = p->next;
		p->next = newNode;
		newNode->val = val;
		m_size += 1;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index)
	{
		if (index > m_size - 1 || index < 0) return;
		myListNode* p = m_head;
		while (index != 0)
		{
			p = p->next;
			--index;
		}
		myListNode* delNode = p->next;;
		p->next = p->next->next;
		m_size -= 1;
		delete delNode;
	}
public:
	int m_size;
	myListNode* m_head;
	myListNode* m_tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```