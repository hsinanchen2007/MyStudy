## LRU

### 概念

LRU 是最近最少使用 Least Recently Used 的缩写。一种常用的页面置换算法，常用来设计缓存。

每次缓存空间不足时，选择缓存中最久没有使用的缓存进行删除，然后写入新的缓存。

获取数据 get(key) 方法：如果密钥 key 存在于缓存中，则获取对应的 value 并将这个缓存标记为访问，否则返回 -1。

写入数据 put(key, value) 方法：如果密钥 key 不存在，则写入其 value。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的缓存，然后进行写入。

### 设计

为了保证 get 和 put 都是 $O(1)$ 的，这里用双向链表+哈希表进行构建。双向链表修改时 $O(1)$ ，使用单链表的话修改是 $O(n)$ 的。

哈希表用于 $O(1)$ 的进行 get 操作，双向链表用于维护时间的访问顺序，一旦访问了就将这个节点移动到链表头。

get 操作时，找到了就将节点移动到链表头并返回 value 值，否则返回 -1。

put 操作时，如果此时缓存已经满了，就先移除最久没有使用的缓存，也就是链表的尾节点，并删除哈希表的对应位置。然后进行插入，新节点被放置在链表头部。

### 实现

[Leetcode 146 LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)

这里是双向链表是手写的，所以需要一个头结点和尾节点。

```cpp
class LRUCache
{
	struct node
	{
		int val;
		int key;
		node* pre;
		node* next;

		node(): val(0), key(0), pre(nullptr), next(nullptr)
		{
		}
	};

	node* head;
	node* tail;
	unordered_map<int, node*> map;
	int capacity;

	void addNode(node* node)
	{
		node->next = head->next;
		node->pre = head;
		head->next->pre = node;
		head->next = node;
		map[node->key] = node;
	}

	void deleteNode(node* node, bool del)
	{
		node->pre->next = node->next;
		node->next->pre = node->pre;
		if (del)
		{
			map.erase(node->key);
			delete node;
		}
	}

	void moveToHead(node* node)
	{
		deleteNode(node, false);
		addNode(node);
	}

public:
	LRUCache(int capacity)
	{
		this->capacity = capacity;
		head = new node();
		tail = new node();
		head->next = tail;
		tail->pre = head;
	}

	~LRUCache()
	{
		while (head != nullptr)
		{
			const auto temp = head;
			head = head->next;
			delete temp;
		}
	}

	int get(int key)
	{
		if (map.count(key) == 0) return -1;
		const auto node = map[key];
		moveToHead(node);
		return node->val;
	}

	void put(int key, int value)
	{
		if (map.count(key) == 0)
		{
			const auto temp = new node();
			temp->key = key;
			temp->val = value;
			addNode(temp);
		}
		else
		{
			const auto temp = map[key];
			temp->val = value;
			moveToHead(temp);
		}
		if (map.size() > capacity) deleteNode(tail->pre, true);
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

---

## LFU

## 概念

最不经常使用算法。这个缓存算法使用一个计数器来记录每个缓存的使用次数，缓存满时选择使用次数最低的且是最久没有使用的缓存进行删除。

这个方法并不经常使用，因为它无法对一个拥有最初高访问率之后长时间没有被访问的缓存负责。

获取数据 get(key) 方法：如果密钥 key 存在于缓存中，则获取对应的 value 并将这个缓存的使用次数 +1，否则返回 -1。

写入数据 put(key, value) 方法：如果密钥 key 存在，则修改对应的 value 值，并把使用次数 +1。如果密钥 key 不存在，先判断缓存是否已经满了，如果满了，则删除最小使用次数中最久没有访问的缓存，然后再写入这个 key 对应 value ，并设置访问次数为 1 。

### 设计

这里使用的了两个哈希表，保证 get 和 put 都是 $O(1)$ 的。

一个哈希表用于存放 key 和节点的对应关系，用于 $O(1)$ 的进行 get 操作。

一个哈希表以使用次数为 key ，以一个双向链表为 value 。每一个双向链表类似于 LRU ，按时间顺序存放这个使用次数下的节点，最新的在链表头，最久没有访问的在链表尾。

然后还需要一个变量记录当前最小的使用次数。

第二个哈希表可以用一个双向链表替代，效果不变。

get 操作时，找到了就将节点从当前的链表移除，并将使用次数 +1 ，然后放置在此时对应的使用次数的链表头部（这个时候如果旧的链表已经空了，需要删除空链表，同时判断最小使用次数是否需要更新）并返回 value 值，否则返回 -1。

put 操作时，**先看能不能找到这个 key** ：

- 能找到：**修改对应的 value ，然后将节点从当前的链表移除，并将使用次数 +1 ，然后放置在此时对应的使用次数的链表头部**（这个时候如果旧的链表已经空了，需要删除空链表，同时判断最小使用次数是否需要更新）并更新哈希表，这个操作类似与 get 。（这里不能删掉现有的然后插入一个使用次数为 1 的节点）

- 找不到：先看缓存是否已经满了，满了则删除最小使用次数对应的链表的尾部节点。然后进行插入，设置使用次数为 1 ，并更新最小使用次数和哈希表。

### 实现

[Leetcode 460 LFU缓存](https://leetcode-cn.com/problems/lfu-cache/)

这里使用的是双哈希表，使用了 list 作为双向链表。

```cpp
class LFUCache
{
	struct Node
	{
		int key;
		int value;
		int freq;

		Node(int key, int value, int freq)
			: key(key), value(value), freq(freq)
		{
		}
	};

	int capacity;
	int minFreq;
	unordered_map<int, list<Node>::iterator> hash;
	unordered_map<int, list<Node>> freqMap;

	void addFreq(const list<Node>::iterator& now)
	{
		const auto key = now->key, value = now->value, freq = now->freq;
		eraseNode(now);

		freqMap[freq + 1].emplace_front(key, value, freq + 1);
		hash[key] = freqMap[freq + 1].begin();
	}

	void eraseNode(list<Node>::iterator now)
	{
		const auto key = now->key, freq = now->freq;
		hash.erase(key);
		freqMap[freq].erase(now);
		if (freqMap[freq].empty())
		{
			if (freq == minFreq) minFreq++;
			freqMap.erase(freq);
		}
	}

public:
	LFUCache(int capacity)
		: capacity(capacity), minFreq(0)
	{
	}

	int get(int key)
	{
		if (capacity == 0) return -1;
		if (hash.count(key) == 0) return -1;
		const auto value = hash[key]->value;
		addFreq(hash[key]);
		return value;
	}

	void put(int key, int value)
	{
		if (capacity == 0) return;
		if (hash.count(key) == 0)
		{
			if (hash.size() == capacity) eraseNode(--freqMap[minFreq].end());

			freqMap[1].emplace_front(key, value, 1);
			hash[key] = freqMap[1].begin();
			minFreq = 1;
		}
		else
		{
			hash[key]->value = value;
			addFreq(hash[key]);
		}
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

