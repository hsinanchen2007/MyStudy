leetcode 已经支持了uthash, 关于uthash的详细说明可以参考 [uthash User Guide](https://troydhanson.github.io/uthash/userguide.html)。

基本的使用方法如下：

- 定义一个结构体
```C
struct hash_entry {
    void *key;              /* we'll use this field as the key */
    int visitd;
    UT_hash_handle hh;      /* makes this structure hashable */
};
struct hash_entry *hash = NULL;
```

- 查找元素
```C
    struct hash_entry * temp; 
    HASH_FIND_PTR(hash, &head, temp);
    if (temp == NULL) { // temp 为0, 则说明在hash 中没有查找到head
        temp = (struct hash_entry *)malloc(sizeof(struct hash_entry));
        temp->key = (void *)head;
        temp->visitd = 1;
        HASH_ADD_PTR(hash, key, temp);  // 向 hash 中加入元素temp，temp的键为 head
    } else {
        res = (struct ListNode *)temp->key;
        res->next = NULL;
        return res;
    }
```

### 代码实现

```C
struct hash_entry {
    void *key;              /* we'll use this field as the key */
    int visitd;
    UT_hash_handle hh;      /* makes this structure hashable */
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct hash_entry *hash = NULL;
    struct ListNode *res = NULL;
    while(head != NULL) {
        struct hash_entry * temp; 
        HASH_FIND_PTR(hash, &head, temp);
        if (temp == NULL) {
            temp = (struct hash_entry *)malloc(sizeof(struct hash_entry));
            temp->key = (void *)head;
            temp->visitd = 1;
            HASH_ADD_PTR(hash, key, temp);
        } else {
            res = (struct ListNode *)temp->key;
            res->next = NULL;
            return res;
        }
        head = head->next;
    }
    return NULL;
}
```