## 辅助链表

创建新链表，边去重，边添加

```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode dummy = ListNode(-1);  
        ListNode* prev = &dummy;   
        while (head){
            while (head->next && head->val == head->next->val){
                head = head->next;
            }
            prev->next = head;
            prev = prev->next;
            head = head->next;
        }
        return dummy.next;
    }
};
```
## 直接修改

遇到重复直接跳过

```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = head;   // 注意这里需要取地址&
        while (prev != NULL && prev->next != NULL){
            if (prev->val == prev->next->val){
                prev->next = prev->next->next;
            }
            else{
                prev = prev->next;
            }
        }
        return head;
    }
};
```
github pages：https://aiaimuti.github.io/ 里面有很多关于C++的总结

