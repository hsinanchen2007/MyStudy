```cpp
class LRUCache
{
private:
	int size;		//当前链表长度
	int cap;		//链表最大容量
	/*双向链表节点*/
	struct binListNode
	{
		int key;	//保存key是为了在dic中删除节点方便查找
		int val;
		binListNode *prev;
		binListNode *next;
		binListNode(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
	};
	unordered_map<int, binListNode*> dic;		//保存key和链表节点指针
	binListNode* head;		//虚拟的head
	binListNode* tail;		//虚拟的tail

	/*将节点放到head之后*/
	void pushToHeadNext(binListNode* node)
	{
		node->prev = head;
		node->next = head->next;
		node->next->prev = node;
		node->prev->next = node;
	}
	/*将节点移出链表*/
	void getOutOfList(binListNode* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
public:
	/*构造函数*/
	LRUCache(int capacity)
	{
		size = 0;
		cap = capacity;
		head = new binListNode(-1, -1);
		tail = new binListNode(-1, -1);
		head->next = tail;
		tail->prev = head;
	}
	int get(int key)
	{
		if (dic.find(key) != dic.end())
		{
			binListNode *curr = dic[key];
			/*先摘除*/
			getOutOfList(curr);
			/*再移动到head后面*/
			pushToHeadNext(curr);

			return curr->val;
		}
		else
		{
			return -1;
		}
	}
	void put(int key, int value)
	{
		/*key已存在*/
		if (dic.find(key) != dic.end())
		{
			dic[key]->val = value;
			binListNode *curr = dic[key];
			/*先摘除*/
			getOutOfList(curr);
			/*再移动到head后面*/
			pushToHeadNext(dic[key]);
		}
		/*key不存在，需新增*/
		else
		{
			/*满了，需先删除tail之前的那个节点*/
			if (size == cap)
			{
				binListNode* temp = tail->prev;
				getOutOfList(temp);
				dic.erase(temp->key);
				delete temp;
			}
			/*没满，size++*/
			else
			{
				size++;
			}
			/*head后面插入新增节点*/
			binListNode* node = new binListNode(key, value);
			pushToHeadNext(node);

			dic[key] = node;
		}
	}
};
```