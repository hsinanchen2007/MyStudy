### 解题思路
郁闷啊。。。为什么我幸幸苦苦造的轮子，比别人直接用stl慢了这么多。有没有大佬指点下如何改进。
hashMap（挂表法） +  双向链表
每次get或者put，都将相应的节点移动到双向表头，删除节点时从双向表尾部开始删除，同时从挂表中删除。
双项链表和hashMap共用节点，所以节点node中有三个指针，pre和rear作用于双向表，next作用于hashMap。
双项链表和挂表均为有头链表，其数据项无意义。
### 代码
```cpp
class LRUCache
{
private:
	struct node
	{
		int key;
		int val;
		node* pre;
		node* rear;
		node* next;
		node(   int key, 
                int value = -1, 
                node* pre = nullptr, 
                node* rear = nullptr, 
                node* next = nullptr )
		{
			this->key = key;
			this->val = value;
			this->pre = pre;
			this->rear = rear;
			this->next = next;
		}
	};

	int capacity;
	int size;
	int arrlen; //数组长度。
	node** Cache;  //hashMap。
	node* head;  //双向链表头结点。
	node* tail;  //双向链表尾节点。

public:
	LRUCache(int capacity)
	{
		this->size = 0;
		this->capacity = capacity;
		//给数组取一个合适的大小。
        if(capacity<=512)  
            arrlen = capacity;
		else if (capacity <= 1024)
            arrlen = 512;
		else
			arrlen = capacity / 2;
		Cache = new node* [arrlen];
		//初始化
		for (int i = 0; i < arrlen; i++)
		{
			Cache[i] = new node(i);
		}
		head = new node(-1);
		tail = new node(-1);
		head->rear = tail;
		tail->pre = head;
	}
	~LRUCache()
	{
		for (int i = 0; i < arrlen; i++)
		{
			node* tmp = nullptr;
			while (Cache[i]->next)
			{
				tmp = Cache[i]->next;
				Cache[i]->next = tmp->next;
				delete tmp;
			}
			delete Cache[i];
		}
		delete[] Cache;
		delete head, tail;
	}
	int get(int key)
	{
		node* tmp = findPtr(key);  //取得对应节点的地址。
		if (!tmp)
			return -1;
		else
		{
			//将节点从双向链表中取出，
			tmp->pre->rear = tmp->rear;
			tmp->rear->pre = tmp->pre;
			//将节点插入到双项链表的头部
			tmp->pre = head;
			tmp->rear = head->rear;
			head->rear = tmp;
			tmp->rear->pre = tmp;
			return tmp->val;
		}
	}
	void put(int key, int value)
	{
		if (get(key) != -1)
		{
			update(key,value);   //若HashMap中已存在，更新value。注意update不进行双向表的操作，		
		}                        //因为get(key)已经进行了移动节点的操作。
		else if (size < capacity)
		{
			size++;
			insert(key, value);  //insert中已进行了移动节点的操作。
		}
		else
		{
			DeleteUnuse();       //删除最老的节点。内部进行了双向表的操作。
			insert(key, value);  //插入节点，内部进行了双向表的操作。
			size++;
		}
	}

private:
	inline void DeleteUnuse()
	{
		//将最老节点从双向表中移除。
		node* tmp = tail->pre;
		tmp->pre->rear = tail;
		tail->pre = tmp->pre;
		//取得最老节点的key。
		int key = tmp->key;  
		//将最老节点从Cache（hashMap）中移除。
		for (node* tar= Cache[key % arrlen]; tar; tar=tar->next)
		{
			if (tar->next == tmp)
			{
				tar->next = tmp->next;
				break;
			}
		}
		delete tmp;
		size--;
	}
	inline void insert(int key, int value)
	{
		int index = key % arrlen;  //计算hashCode，采用取余法。
		//构造节点并插入双向表和挂表的头部（头结点后面）。
		node* item = new node(key, value, head, head->rear, Cache[index]->next);
		Cache[index]->next = item;
		head->rear = item;
		item->rear->pre = item;
	}
	inline void update(int key, int value)  //注意不需要改变双向表。get方法已经移动过。
	{
		node* tmp = findPtr(key);
		tmp->val = value;
		//tmp->pre->rear = tmp->rear; 
		//tmp->rear->pre = tmp->pre;
		//tmp->pre = head;
		//tmp->rear = head->rear;
		//head->rear = tmp;
		//tmp->rear->pre = tmp;
	}
	inline node* findPtr(int key)
	{
		int index = key % arrlen;
		//根据index遍历挂表，返回对用的结点指针。
		for (node* tmp = Cache[index]->next; tmp; tmp = tmp->next)
		{
			if (tmp->key == key)
			{
				return tmp;
			}
		}
		return nullptr;
	}
};
```