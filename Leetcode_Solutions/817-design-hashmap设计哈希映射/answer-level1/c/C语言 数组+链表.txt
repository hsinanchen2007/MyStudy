### 解题思路
没什么特别的，一般实现
![image.png](https://pic.leetcode-cn.com/51a59320dcc0201b22524b108b6de0a57e161c70f347a0f70b47ecfbccec2ee3-image.png)


### 代码

```c
#define HASH_SIZE	1001
struct MyListNode {
	int key;
	int val;
	struct MyListNode *prev;
	struct MyListNode *next;
};
typedef struct {
    struct MyListNode heads[HASH_SIZE];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
	MyHashMap *map = (MyHashMap*) calloc(1, sizeof(MyHashMap));
	return map;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
	int inx;
	struct MyListNode *node = NULL;
	inx	= key % HASH_SIZE;
	node = obj->heads[inx].next;
	while (node != NULL) {
		if (node->key == key) {
			node->val = value;
			return;
		}
		node = node->next;
	}
	node = (struct MyListNode*)calloc(1, sizeof(struct MyListNode));
	if (node == NULL) {
		return;
	}
	node->key = key;
	node->val = value;
	node->next = obj->heads[inx].next;
	if(obj->heads[inx].next != NULL){
		obj->heads[inx].next->prev = node;
	}
	obj->heads[inx].next = node;
	node->prev = &obj->heads[inx];
	return;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
	int inx;
	struct MyListNode *node = NULL;
	inx	= key % HASH_SIZE;
	node = obj->heads[inx].next;
	while (node != NULL) {
		if (node->key == key) {
			return node->val;
		}
		node = node->next;
	}
	return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
	int inx;
	struct MyListNode *node = NULL;
	inx	= key % HASH_SIZE;
	node = obj->heads[inx].next;
	while (node != NULL) {
		if (node->key == key) {
			break;
		}
		node = node->next;
	}
	if (node == NULL) {
		return;
	}
	node->prev->next = node->next;
	if (node->next != NULL) {
		node->next->prev = node->prev;
	}
	
	free(node);
	return;
}

void myHashMapFree(MyHashMap* obj) {
	int i;
	struct MyListNode *node = NULL;
	for (i = 0; i < HASH_SIZE; i++) {
		node = obj->heads[i].next;
		while (node != NULL) {
			node->prev->next = node->next;
			if (node->next != NULL) {
				node->next->prev = node->prev;
			}
			free(node);
			node = obj->heads[i].next;
		}
	}
	free(obj);
	return;
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
```