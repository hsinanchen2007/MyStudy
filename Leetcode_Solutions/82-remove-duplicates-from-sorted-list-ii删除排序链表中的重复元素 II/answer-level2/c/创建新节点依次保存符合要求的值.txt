## 思路
要在不破坏参数链表结构的前提下返回链表指针，所以当遍历参数链表时每当遇到符合要求的节点都需要开辟新的节点保存值。
### 1. 创建两个指针: 
```
// 1. 用于储存符合要求的值
struct ListNode realHead = {0, NULL};
struct ListNode *pre = &realHead;
// 2. 用于遍历重复值的临时指针
struct ListNode *dup;
```
### 2. 遍历链表，因为需要判断当前节点和下一个节点的值是否相同，所以需要同时判断当前节点和下一个节点同时不为空
```
while(head && head->next){
  // 1. 值相等的情况
  if(head->val == head->next->val){
    // 如果当前节点与下一个节点的值相等，则使用临时指针继续遍历链表，找到下一个值不同的节点，并将该值不同的节点赋值给 head，下一次循环即从该节点开始
    dup = head;
    while(dup && dup->val == head->val){
        dup = dup->next;
    }
    // 走到这里有两种情形：1. dup == NULL 2. dup 所指节点的值与 head 所指的节点值不相同
    head = dup;
  }
  // 2. 值不等的情况
  else 
  {
            // 创建新节点
            struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
            // 保存符合要求的值
            next->val = head->val;
            next->next = NULL;
            
            // 连接上一个节点
            pre->next = next;
            // 将 pre 指针移动到当前新创建的节点
            pre = next;
            // 将 head 向后移动一个节点，继续循环
            head = head->next;
  }
}
// 循环结束，如果当前节点不为空，则连接当前节点
 if(head){
        struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
        next->val = head->val;
        next->next = NULL;
        pre->next = next;
 }
 return realHead.next;
```