### 解题思路
遍历的时候保留前向节点的指针就可以了。这问题不难，不过我发现很多人都忘了释放被删除节点的内存了

### 代码

```c
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *prev = NULL, *cur = head, *t;
    while(cur != NULL){
        if(cur->val == val){
            if(prev == NULL){
                head = cur->next;
            }else{
                prev->next = cur->next;
            }
            t = cur;
            cur = cur->next;
            free(t);
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}
```