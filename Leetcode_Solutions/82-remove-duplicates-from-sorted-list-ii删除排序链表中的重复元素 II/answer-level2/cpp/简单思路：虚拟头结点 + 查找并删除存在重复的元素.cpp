1、新建虚拟头结点
2、找到存在重复元素的值，通过判断下个及下下个元素的值是否相等来得到
3、判断下个元素的值是否为重复元素的值，是的话删除它
4、小心while中访问空指针就行，最后返回结果

```c++
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* preHead = new ListNode(0);
        preHead->next = head;

        ListNode* cur = preHead;
        int delVal;
        while(cur->next != NULL){
            if (cur->next->next != NULL && cur->next->val == cur->next->next->val) {
                delVal = cur->next->val;
                while(cur->next != NULL && cur->next->val == delVal){
                    ListNode* delNode = cur->next;
                    cur->next = delNode->next;
                    delete delNode;
                }
            } else {
                cur = cur->next;
            }
        }
        ListNode* newHead = preHead->next;
        delete preHead;
        return newHead;
    }
```
