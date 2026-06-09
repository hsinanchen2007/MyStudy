

解法1：将此节点的数值与指向都修改为下一个节点的。复制模仿了下一个节点。

```c
void deleteNode(struct ListNode* node) {
    node->val=node->next->val;
    node->next=node->next->next;
}
```


解法2：看评论区的大佬抖机灵，直接把指向此节点的指针的数据修改为下个节点的。复制模仿了下一个节点，与解法1目的是一样的。

```c
void deleteNode(struct ListNode* node) {
    *node=*(node->next);
}
```