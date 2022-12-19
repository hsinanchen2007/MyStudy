很容易想到，把下一个节点的val和next字段的值，都复制到当前节点上，然后删除下一个节点。

考虑到通用性，节点的拷贝应当避免显示指定成员变量：
```C
node->val = node->next->val;
node->next = node->next->next;
```
而是应当用`=`操作符，或者显示地`memcpy`:
```C
memcpy(node, node->next, sizeof(struct ListNode));//or: *node = *(node->next);
```

此外，题目的意思是删除节点，应当是要释放一个节点大小的内存，而不是“跳过去”，因此在开始拷贝下一个节点各个字段的值到当前节点之前，应当标记后一个节点，等赋值结束后，删除此标记节点。完整代码如下：
```C
void deleteNode(struct ListNode* node) {
    struct ListNode* shadow = node->next;
    memcpy(node, node->next, sizeof(struct ListNode));//or: *node = *(node->next);
    free(shadow);
    shadow = NULL;
}
```