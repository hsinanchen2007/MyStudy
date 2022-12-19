### 解题思路
首先实现一个最近最少使用算法（LRU）的缓存。在这个缓存的基础上添加访问次数计数器。
每次缓冲满时，根据访问次数计数器选择访问次数最小的页调出。当有多个访问次数最小的页时，可以根据LRU的特性，选择链表里面最久未访问的进行调出

题目中的例子：
页的数据结构(key,val,times)，每一列都是一个动作执行完毕后，缓存的状态

-----------------------------> 动作执行过程-------------------------------------->  上面 rear(最近访问过的页)
(1,1,1) (2,2,1) (1,1,2) (3,3,1) (get2) (3,3,2) (4,4,1) (get1) (3,3,3) (4,4,2)
        (1,1,1) (2,2,1) (1,1,2)        (1,1,2) (3,3,2)        (4,4,1) (3,3,3)
-----------------------------> 动作执行过程-------------------------------------->  下面 head(最久未访问的页)

调入操作：
如果Key值已经在缓存中，更新一下对应的value
如果缓存有剩余空间，直接插进rear后面。调入了缓存，同时作为最近访问过的页。
如果缓存已经满了，从head向rear遍历，找出times值最小的页换出即可。当有多个页的times值都是最小的，因为我们是从head（最久未访问的页）向rear(最近访问过的页)遍历的，所以只选择第一个最小的页进行换出即可。
访问操作：
查找Key对应的页是不是在缓存中，如果是，先把这个页调到rear，作为最近访问过的页，在返回对应的value值

辅助数据结构：类似队列操作的一个链表

经验：
1 容量为0的时候 put直接return即可 get直接return -1
2 put操作要包含对key-value的更新操作
3 要考虑进行调入调出的页在链表头尾补时，链表需要进行判断一下再操作，一面越界或者链表断裂

没有实现O(1)那种算法，但是能通过
![image.png](https://pic.leetcode-cn.com/023257cd863b04418aabaf828b16b4b7ac512541c42acff33716539422594e80-image.png)

总结：先看一下操作系统的内存管理部分，再看这道题比较好理解。

### 代码

```c
//------------------------------------一个基础队列有：建立新节点、队尾插入新节点、释放空间，三种操作
typedef struct Node
{
	int key;
	int val;
	int times;
	struct Node* next;
}Node;
Node* newNode(int Key, int Val, int Times)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->key = Key;
	n->val = Val;
	n->times = Times;
	n->next = 0;
	return n;
}
Node* queuePush(Node* Rear, int Key, int Val)
{
	Node* n = newNode(Key, Val, 1);
	n->next = Rear->next;
	Rear->next = n;
	return n;
}
Node* del(Node* Head, Node* Rear)
{
	while (Head != 0)
	{
		Node* n = Head;
		Head = Head->next;
		free(n);
	}
	return 0;
}
//------------------------------------解答
typedef struct {
	Node* head;
	Node* rear;
	int length;//当前缓存中页数
	int capacity;//缓存容量
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
	LFUCache* cache = (LFUCache*)malloc(sizeof(LFUCache));
	cache->head = newNode(0, 0,0);
	cache->rear = cache->head;
	cache->length = 0;
	cache->capacity = capacity;
	return cache;
}

int lFUCacheGet(LFUCache* obj, int key) {
	Node* iter = obj->head;
	while (iter->next != 0 && iter->next->key != key)
		iter = iter->next;
	if (iter->next != 0)
		if (iter->next != obj->rear)
		{
			//如果缓存中有对应的页，还要再看一下是不是最近访问过的页，不然下面的操作会把链表截断
			Node* n = iter->next;
			iter->next = n->next;//如果n是rear，这一步会截断链表的(但不会丢页)
			++(n->times);
			//取下来的页放到链表的rear端
			n->next = obj->rear->next;
			obj->rear->next = n;
			obj->rear = obj->rear->next;
			return obj->rear->val;
		}
		else
		{
			++(iter->next->times);
			return iter->next->val;
		}
	else
		return -1;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
	//情况一 缓存容量本来就是0
    if(obj->capacity==0)return;
	//情况二 缓存中已经有key对应的页，更新一下value即可
    for(Node* iter=obj->head->next;iter!=0;iter=iter->next)
        if(iter->key==key)
        {
            iter->val=value;
            ++(iter->times);
            return;
        }    
	//情况三 缓存还有剩余空间
	if (obj->length < obj->capacity)
	{
		obj->rear = queuePush(obj->rear, key, value);
		++(obj->length);
	}
	//情况四 缓存满
	else
	{	//先找出访问量最少的页
		Node* minNodePre=0; int minTimes = (~((unsigned)0)) >> 1;
		for (Node* iter = obj->head; iter->next != 0; iter = iter->next)
			//注意这个判断是用小于而不是小于等于，因为我们要找的是“第一个最小的times”。
			//这个链表是有序的（根据LRU原理所创建，从head的最久未访问到rear的最近访问的页面），所以选“第一个”&&"最小times"进行记录即可。
			if (iter->next->times < minTimes)
			{
				minNodePre = iter;
				minTimes = iter->next->times;
			}
		//把最少的页调出（从链表删除对应节点）
		Node* n = minNodePre->next;
        if(n==obj->rear)
            obj->rear=minNodePre;
		minNodePre->next = n->next;
		free(n);
		//把新页放进链表rear端（作为最近访问过的页）
		obj->rear = queuePush(obj->rear, key, value);
	}
}

void lFUCacheFree(LFUCache* obj) {
	obj->rear = del(obj->head, obj->rear);
    free(obj);
}

```