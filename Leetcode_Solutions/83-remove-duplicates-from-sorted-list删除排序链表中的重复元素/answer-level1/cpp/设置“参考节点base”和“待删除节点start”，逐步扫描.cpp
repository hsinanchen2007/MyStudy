```
ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* base = head;  //参考节点
        ListNode* start = head->next;  //以第2个节点开始
        while(start != NULL){
            if(start->val == base->val){
                //删除重复节点start：
                base->next = start->next;
                delete start;
                start = base->next;
            }
            else{  //不重复就移动
                base = base->next;
                start = start->next;
            }
        }
        return head;
    }
```
