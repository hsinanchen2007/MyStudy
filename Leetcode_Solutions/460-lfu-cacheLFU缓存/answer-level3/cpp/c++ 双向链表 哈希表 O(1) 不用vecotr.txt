### 解题思路
算法思路同官方题解。
跟官方题解的差别就在于哈希表的value，我没有用vector或者list，而是让当前freqMap最后一个节点指向下一个freqMap的头结点，这样可以方便添加与删除，也很好的利用了双向链表的特性。
由于重复的代码太多了，就通过define压缩了一下代码行数

### 代码

```cpp
struct DListNode {
	int key;
	int val;
	int freq;
	DListNode * next;
	DListNode * prev;
	DListNode(const int & _key = int(), const int & _val = int(), const int & _freq = int(),
		DListNode * _next = nullptr, DListNode * _prev = nullptr)
		: key(_key), val(_val), freq(_freq), next(_next), prev(_prev) {}
};
class LFUCache {
public:
#define ADDNEWNODE(freq, node) if (nullptr == freqMap[(freq)]->next) {\
	freqMap[(freq)+1] = new DListNode((freq)+1, -1);\
	freqMap[(freq)]->next = freqMap[(freq)+1];\
	freqMap[(freq)+1]->prev = freqMap[(freq)];\
}\
	  (node)->next = freqMap[(freq)]->next;\
	  freqMap[(freq)]->next->prev = (node);\
	  (node)->prev = freqMap[(freq)];\
	  freqMap[(freq)]->next = (node);\
	  (node)->prev = freqMap[(freq)];
#define DEL(node) (node)->next->prev = (node)->prev;\
	(node)->prev->next = (node)->next;
#define NEWNODE DListNode * dNode = new DListNode(key, value, 1);\
	keyMap[key] = dNode;\
	ADDNEWNODE(1, dNode);\
	minFreq = 1;
#define UPDATE(value) DListNode * tmp = keyMap[key];\
	tmp->val=(value);\
	DEL(tmp);\
	++tmp->freq;\
	ADDNEWNODE(tmp->freq, tmp);\
	if (-1 == freqMap[minFreq]->next->val) {\
		++minFreq;\
	}
	int capacity;
	int size;
	int minFreq;
	unordered_map<int, DListNode*> keyMap;
	unordered_map<int, DListNode*> freqMap;
	LFUCache(int capacity) {
		minFreq = size = 0;
		this->capacity = capacity;
		freqMap[0] = new DListNode(0, -1);
		freqMap[1] = new DListNode(1, -1);
		freqMap[0]->next = freqMap[1];
		freqMap[1]->prev = freqMap[0];
	}
	int get(int key) {
		if (0 == capacity) {
			return -1;
		}
		if (keyMap.end() == keyMap.find(key)) {
			return -1;
		}
		int ans = keyMap[key]->val;
		UPDATE(ans);
		return ans;
	}
	void put(int key, int value) {
		if (0 == capacity) {
			return;
		}
		if (keyMap.end() == keyMap.find(key)) {
			if (size < capacity) {
				NEWNODE;
				++size;
			}
			else {
				DListNode * delNode = freqMap[minFreq + 1]->prev;
				keyMap.erase(delNode->key);
				DEL(delNode);

				NEWNODE;
			}
		}
		else {
			UPDATE(value);
		}
	}
};
```