用下一个节点的值替换当前节点的值
```
void deleteNode(struct ListNode* node) {
    while (node != NULL) {
        if (node->next       != NULL) node->val = node->next->val;
        if (node->next->next == NULL) node->next = NULL;
        node = node->next;
    }
}
```

