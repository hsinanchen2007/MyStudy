
```
// 1.创建2个左右的虚拟节点来放大于 小于等于的节点
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;

        ListNode* lDummyNode = new ListNode(-1);
        ListNode* rDummyNode = new ListNode(-1);

        ListNode* l = lDummyNode, *r = rDummyNode;
        ListNode* cur = head;
        while(cur != nullptr) {
            if (cur->val < x) {
                l->next = cur;
                l = l->next;
            }else {
                r->next = cur;
                r = r->next;
            }

            cur = cur->next;
        }

        l->next = nullptr;
        r->next = nullptr;
        l->next = rDummyNode->next;
        delete rDummyNode;

        ListNode* resultNode = lDummyNode->next;
        delete lDummyNode;
        return resultNode;
    }
```
