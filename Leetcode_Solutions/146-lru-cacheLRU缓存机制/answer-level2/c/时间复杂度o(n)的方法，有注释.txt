### 解题思路
最后一个测试用例未通过，原因时间超时，仅供参考。
应该是由于get和put的时间复杂度不符合要求

### 代码

```c
typedef struct LRUCache{
    int value;
    int key;
    struct LRUCache* pre;
	struct LRUCache* next;
	int count;
} LRUCache;


struct LRUCache* lRUCacheCreate(int capacity) {
    struct LRUCache *head=(struct LRUCache*)malloc(sizeof(struct LRUCache));//假头部
	head->next=NULL;head->pre=NULL;
	struct LRUCache *tail=(struct LRUCache*)malloc(sizeof(struct LRUCache));//假尾部
	tail->next=NULL;tail->pre=NULL;
	struct LRUCache *p=head;//指向head的指针，方便组装。
	for(int i=0;i<capacity;i++){
		struct LRUCache *node=(struct LRUCache*)malloc(sizeof(struct LRUCache));
		node->value=-1;//设置一个fu数代表没有赋值
		node->count=0;
		p->next=node;node->pre=p;
		p=node;
	}
	p->next=tail;//连接上假尾部
	tail->pre=p;
	return head;
}

int lRUCacheGet(LRUCache* obj, int key) {
	LRUCache *p=obj->next;int value=-1;
	while(p->next!=NULL){//只有假尾部的next才是空
		if(p->key==key){
			p->count=0;
			value=p->value;
		}else{
			p->count++;
		}
		p=p->next;
	}
	return value;
}

void lRUCachePut(struct LRUCache* obj, int key, int value) {
	struct LRUCache *p=obj->next;int maxcount=-1;struct LRUCache *q;
	while(p->next!=NULL){
		p->count++;
		if(p->count>maxcount){maxcount=p->count;q=p;}//用q来标记最大的那个count值，供LRU使用
		if(p->key==key){//key存在则写入value
			p->value=value;p->count=0;break;
		}else if(p->value==-1){//不存在key但又空位，则插入
			p->key=key;p->value=value;p->count=0;break;
		}
		p=p->next;
	}
	if(p->next==NULL){//已经遍历到最后了，所以只能覆盖，让新值插入
		//开始覆盖旧的值
		q->key=key;q->value=value;q->count=0;
	}
	while(p->next!=NULL){//如果没到最后就找到了合适的位置
		if(p->value!=-1){
			p->count++;
		}
		p=p->next;
	}
}

void lRUCacheFree(struct LRUCache* obj) {
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
```