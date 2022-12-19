暴力双向链表，已无心优化。不过思路很直接；
```c
struct DListNode {
  int key;                         //键
  int value;                       //值
  int freq;                        //访问频率
  struct DListNode *prior, *next;  //前驱，后继
};

typedef struct {
  struct DListNode* head;
  int capacity;
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
  LFUCache* cache = (LFUCache*)malloc(sizeof(LFUCache));
  // 初始化设置头结点
  cache->capacity = capacity;
  cache->head = (struct DListNode*)malloc(sizeof(struct DListNode));
  cache->head->prior = NULL;
  cache->head->next = NULL;
  return cache;
}

// 结点提升，插入排序的感觉，相同频率的放在同频率的最前面
void lFUCaacheUp(LFUCache* obj, struct DListNode* p) {
  struct DListNode* q;
  p->freq++;
  if (p->next) {  //如果当前结点是最后一个结点，
    p->next->prior = p->prior;
    p->prior->next = p->next;  //将p结点从链表上摘下
  } else
    p->prior->next = NULL;
  q = p->prior;
  while (q != obj->head && q->freq <= p->freq)  //向前查找p结点的插入位置
    q = q->prior;
  p->next = q->next;  //将p结点插入，排在同频率的第一个
  if (q->next != NULL)
    q->next->prior = p;
  p->prior = q;
  q->next = p;
}

int lFUCacheGet(LFUCache* obj, int key) {
  int count = 0;
  struct DListNode *p = obj->head->next, *q;
  // 遍历链表，查找元素
  while (p && p->key != key && count < obj->capacity) {
    p = p->next;
    count++;
  }
  // 不存在返回 -1
  if (p == NULL || count == obj->capacity) return -1;
  // 存在：访问频率加一，按访问频率调整链表，返回值
  lFUCaacheUp(obj, p);
  return p->value;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
  int count = 0;
  struct DListNode *p = obj->head, *q;
  // 先遍历链表找 key 是否存在
  while (p->next != NULL && p->next->key != key && count < obj->capacity) {
    p = p->next;
    count++;
  }
  // key已存在更新 结点，按访问频率调整链表
  if (p->next != NULL && p->next->key == key && count < obj->capacity) {  //key值已存在
    p->next->value = value;
    lFUCaacheUp(obj, p->next);
    return;
  }
  // key不存在，重新找到链表插入位置：仅访问过一次的结点（只有一次put）的最前面
  count = 0;
  p = obj->head;
  while (p->next != NULL && p->next->freq > 1 && count < obj->capacity) {
    p = p->next;
    count++;
  }
  if (count == obj->capacity) {  //到达表尾，直接覆盖尾结点
    p->key = key;
    p->value = value;
    p->freq = 1;
  } else {  //未到达表尾
    // 创建结点，存值
    struct DListNode* s = (struct DListNode*)malloc(sizeof(struct DListNode));
    s->key = key;
    s->value = value;
    s->freq = 1;
    // 插入
    s->next = p->next;
    s->prior = p;
    p->next = s;
    if (s->next)
      s->next->prior = s;
    else
      s->next = NULL;
  }
}

void lFUCacheFree(LFUCache* obj) {
  if (obj == NULL) return;
  struct DListNode* s;
  while (obj->head) {
    s = obj->head;
    obj->head = obj->head->next;
    free(s);
  }
  free(obj);
}
```